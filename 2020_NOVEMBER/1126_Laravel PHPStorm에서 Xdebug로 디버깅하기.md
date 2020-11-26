# PHPStorm에서 Xdebug로 디버깅

1126 Laravel 프레임워크 디버깅하기

- PHP 7.4
- Xdebug 3.0.0
- Windows10

LDAP 구축을 하다가 디버깅을 해야하는 상황이 생겼는데, Xdebug가 3.0.0이 되면서 바뀐점도 있었고, 인터넷에 나와있는대로 하니까 잘 안됐다. 그래서 약 3시간 삽질을 하다가 성공.  PHPstorm에서 laravel 프레임워크로 프로젝트를 생성했을 때, Xdebug로 디버깅을 시작하는 방법을 간단하게 정리해보았다.

---

### 설치

http://xdebug.org/download 페이지에 가서

![image-20201126094146965](C:\Users\ADMIN\AppData\Roaming\Typora\typora-user-images\image-20201126094146965.png)

중에 자기 PHP버전에 맞는 것을 다운로드하면 된다. 그리고 {xdebug....}.dll 파일은 자신의 설치된 php 경로/ext 폴더 안에 넣기. 나 같은 경우는 C:\php7\ext 에 넣어주었다.

그 다음 php.ini 설정을 해 주었다.

```
zend_extension="{xdebug 전체 경로}"
xdebug.mode=debug
xdebug.client_port=9003
xdebug.client_host=localhost
xdebug.start_with_request=yes
```

이렇게 설정을 해주면 된다.



### PhpStorm 설정

1. PHPStorm에서 Ctrl + Alt + S 를눌러 세팅으로 들어간다.

2. Languages & Frameworks -> PHP -> Debug 로 들어간다.

   ![image-20201126095351515](C:\Users\ADMIN\AppData\Roaming\Typora\typora-user-images\image-20201126095351515.png)

   다음과 같이 변경한다.

3. Debug-> DBGp Proxy도 들어가서

   ![image-20201126095427298](C:\Users\ADMIN\AppData\Roaming\Typora\typora-user-images\image-20201126095427298.png)

   다음과 같이 변경시켜준다.

4. config/app.php 파일에 들어가서

   ```php
       'debug' => (bool) env('APP_DEBUG', true),
   ```

   로 변경시켜 준다.



### Chrome Extension 다운로드

나는 크롬을 사용해서 디버깅을 진행하였기에 크롬 익스텐션을 다운로드 했고, 다른 브라우저를 쓴다면 찾아보면 될 것 같다.

https://chrome.google.com/webstore/detail/xdebug-helper/eadndfjplgieldjbigjakmdgkmoaaaoc

에 접속해서 설치를 해준다.

![image-20201126095634945](C:\Users\ADMIN\AppData\Roaming\Typora\typora-user-images\image-20201126095634945.png)

에서 ... 버튼을 눌러 옵션으로 가서  IDEKey를 PHPstorm으로 변경시켜 준다.



### 디버깅

```bash
$ php artisan serve
```

로 laravel을 시작하고 자기가 원하는 곳에 Ctrl + F8을 눌러 브레이킹 포인트를 건 다음에 

![image-20201126095914195](C:\Users\ADMIN\AppData\Roaming\Typora\typora-user-images\image-20201126095914195.png)

여기 전화표시를 이렇게 초록색으로 해주고, 실행하면 디버깅창이 뜨면서 디버깅을 시작할 수 있다.



---

### 참고

- https://xdebug.org/
- https://www.jetbrains.com/help/phpstorm/debugging-with-phpstorm-ultimate-guide.html#debugging-a-php-cli-script
- https://defacto-standard.tistory.com/511

