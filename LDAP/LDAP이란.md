# LDAP 이란

2020. 11. 26

### LDAP

> Lightweight Directory Access Protocol

- Active Directory가 디렉터리 서비스를 실행할 때 정보를 제공하는 디렉터리 액세스 프로토콜
- Active Directory가 요청을 이해하고 응답할 수 있도록 LDAP을 준수해야함
- TCP/IP를 통해 서버에서 데이터를 검색하는 프로토콜을 만들었음.
- 운영체제에서 실행할 수 있는 디렉토리 서비스가 있으면, LDAP 사용 가능
- 현재 version 3까지 나옴.
- LDAP에 관한 내용은 추가해 나갈 예정임.

![[Hierachial Directory Tree]](http://quark.humbug.org.au/publications/ldap/images/directory-tree-hierachial.png)



### LDAP vs Database

| LDAP                                                 | DB                                                    |
| ---------------------------------------------------- | ----------------------------------------------------- |
| 데이터 계층적 구조화 가능                            | 가능은 하지만 어려움                                  |
| Object 스타일로 객체 구성 가능 - 구조 상속 받기 가능 | 미리 만든 테이블의 구조를 다른 테이블에서 사용 불가능 |
| 유연성 있는 쿼리 제공                                | SQL                                                   |
| cn=장지석, cn=장*(장으로 시작되는)                   | ... where s like "%장";                               |



### LDAP으로 인증하기

- Binding 이라고도 한다.

- Ldap을 사용할 수 있는 곳은 php나다른 언어, 프레임워크 많지만 가장 기본적인 ldapsearch로 찾는 방법을 선택했다. 

ldapsearch를 설치한다

```
$ sudo apt install ldap-utils # ldapsearch 설치
```

##### 1단계 : 사용자 이름으로 Full DN 찾아내기

```bash
$ ldapsearch -x -b "{검색할 dn ex)dc=example,dc=com}" -H {LDAP URL} -a search "{검색할 LDAP Attribute ex)uid=1234}"  | grep dn
```

이러면 DN을 확인할 수 있게 된다.

##### 2단계 : 인증하기

```bash
$ ldapsearch -x -D "{앞에서 나온 DN}" -W -H {LDAP URL} -b {엔트리 url, 위에서 검색할 dn과 같은 것} -s sub '자신의 ID'
Enter LDAP Password:
```

LDAP Password를 입력하라고 나오고, 거기서 패스워드를 입력하면 된다.





---

참고

1. http://quark.humbug.org.au/publications/ldap/ldap_tut.html
2. 