# PHP Ldap 서버 연결 과정

2020.11.25

LDAP 서버가 어떻게 동작하는지 궁금해서 PHP로 LDAP 서버에 연결을 해보고 싶었다. 처음에는 ONLINE LDAP TEST SERVER에 연결을 해보고, 그 다음 LDAP 서버에 연결을 해서 어떤 구조로 되어있는지 알아보기로 했다.

#### 환경

- PHP 7.4.12

- Laravel 8.12

- LDAP Server -> Linux

  ```
  # extended LDIF
  #
  # LDAPv3
  # base <dc=gldap,dc=com> with scope subtree
  # filter: (objectclass=*)
  # requesting: ALL
  ```



#### 프로젝트 생성

```bash
$ laravel new phpldap
```

#### php ldap auth 설치

```bash
$ composer require jotaelesalinas/laravel-adminless-ldap-auth
```



#### .env 파일에 다음과 같은 내용 추가

```
LDAP_SCHEMA=OpenLDAP

LDAP_HOSTS={LDAP 주소}
LDAP_BASE_DN={LDAP DN 정보}
LDAP_USER_SEARCH_ATTRIBUTE=uid
LDAP_USER_BIND_ATTRIBUTE=uid
LDAP_USER_FULL_DN_FMT=${LDAP_USER_BIND_ATTRIBUTE}=%s,${LDAP_BASE_DN}
LDAP_CONNECTION=default

AUTH_USER_KEY_FIELD=username
```

- AUTH_USER_KEY_FILED 는 요청할 때 unique하게 지정되는 identifier.
- id, email, phonenumber 등이 가능



#### config/auth.php 수정

```php
'providers' => [
    'ldap' => [
        'driver' => 'adminless_ldap',
    ],
], // adminless_ldap 드라이버를 새롭게 설치함.
'auth_user_key' => env('AUTH_USER_KEY_FIELD', null), // 새롭게 추가한다.
'guards' => [
    'web' => [
        'driver' => 'session',
        'provider' => 'ldap',
    ],
//        'api' => [
//            'driver' => 'token',
//            'provider' => 'users',
//            'hash' => false,
//        ],   api 주석 처리
], // provider를 ldap으로 변경해준다. 원래의 user는 삭제한다.
```



#### Adldap와 AdldapAuth 설정 파일을 Publish

```bash
$ php artisan vendor:publish --provider="Adldap\Laravel\AdldapServiceProvider"
$ php artisan vendor:publish --provider="Adldap\Laravel\AdldapAuthServiceProvider"
```



#### config/ldap.php 파일 수정

```php
    'connections' => [
        'default' => [
            'auto_connect' => env('LDAP_AUTO_CONNECT', false),
            'connection' => Adldap\Connections\Ldap::class,
            'settings' => [
                'schema' => env('LDAP_SCHEMA', '') == 'OpenLDAP' ?
                    Adldap\Schemas\OpenLDAP::class :
                    ( env('LDAP_SCHEMA', '') == 'FreeIPA' ?
                        Adldap\Schemas\FreeIPA::class :
                        Adldap\Schemas\ActiveDirectory::class ),

                'hosts' => explode(' ', env('LDAP_HOSTS', '')),
                'base_dn' => env('LDAP_BASE_DN', ''),
                'username' => env('LDAP_ADMIN_USERNAME', ''),
                'password' => env('LDAP_ADMIN_PASSWORD', ''),
                
                'account_prefix' => env('LDAP_ACCOUNT_PREFIX', ''),
                'account_suffix' => env('LDAP_ACCOUNT_SUFFIX', ''),
                'port' => env('LDAP_PORT', 389),
                'timeout' => env('LDAP_TIMEOUT', 5),
                'follow_referrals' => env('LDAP_FOLLOW_REFERRALS', false),
                'use_ssl' => env('LDAP_USE_SSL', false),
                'use_tls' => env('LDAP_USE_TLS', false),
            ],
        ],
    ],
```



#### config/ldap_auth.php 파일 수정

```php
 'identifiers' =>[
     // ...
     'ldap' => [
            'locate_users_by' => env('LDAP_USER_SEARCH_ATTRIBUTE', ''),
            'bind_users_by' => env('LDAP_USER_BIND_ATTRIBUTE', ''),
            'user_format' => env('LDAP_USER_FULL_DN_FMT', ''),
        ],
     // ...
 ]
     
'sync_attributes' => [
        env('AUTH_USER_KEY_FIELD', null) => env('LDAP_USER_SEARCH_ATTRIBUTE', null),
        'name' => 'cn',
        'email' => 'mail',
        'phone' => 'telephonenumber',
    ],
```

- AUTH_USER_KEY_FIELD는 전에 설정했던 username이 들어가는 부분. mail이나 phone을 쓰지않는다면 삭제해도 된다.



#### 인증 확인

```php
$ldapHelper = new LdapHelper($config);
$userCheck = $ldapHelper->retrieveLdapAttribs($request->text, $request->password);

if($userCheck){
    //성공
}else{
    //실패
}
```



#### 리눅스에서 ldap서버 구조 확인해 보는 법

```bash
$  sudo apt install ldap-utils # ldapsearch 설치
$ ldapsearch -x -b {BASE_DN 입력} -H {LDAP_HOST입력}
```





---

#### 참고

1. https://github.com/jotaelesalinas/laravel-adminless-ldap-auth
   - LDAP 관련 설정 및 LdapHelper 
2. https://www.forumsys.com/tutorials/integration-how-to/ldap/online-ldap-test-server/
   - Online LDAP Test 서버
   - Ldap 연결후 확인
3. https://big-blog.tistory.com/638
   - LDAP 디렉터리 노드

4. https://adldap2.github.io/Adldap2/#/
   - ADLDAP 