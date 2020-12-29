# Windows 에서 Laravel Apache로 배포

2020 12 29

Apache가 뭔지는 대충 알았고.. 이제 Laravel 과 연동을 해봐야 한다. windows에 Apache 설치하는 방법은 검색하면 매우 잘 나온다. 근데 Laravel과 Apache로 연동하는 방법은 검색을 좀 빡세게 해야 찾을 수 있었다. 그래서 한 번 정리해 봤다.

---

### .htaccess 수정

Laravel 프로젝트 안에 있는 `.htaccess` 파일을 수정해야 한다.  보통은 그냥 해도 된다.

```xml
<IfModule mod_rewrite.c>
	<IfModule mod_negotiation.c>
        Options -MultiViews
    </IfModule>

    RewriteEngine On

    # Redirect Trailing Slashes...
    RewriteRule ^(.*)/$ /$1 [L,R=301]

    # Handle Front Controller...
    RewriteCond %{REQUEST_FILENAME} !-d
    RewriteCond %{REQUEST_FILENAME} !-f
    RewriteRule ^ index.php [L]
</IfModule>

```

이런 식으로 수정해주면 된다. mod_rewrite 를 사용하도록 해야 Laravel에서 내가 지정한 라우팅이 제대로 동작한다.

---

### httpd.conf 수정

Apache를 Windows에 제대로 설치했다면 아파치 설치폴더(대부분은 C:\Apache24)에 conf 폴더가 있을 것이다. 여기에 들어가면 `httpd.conf` 파일이 보인다. 이를 메모장으로 열어주자.

```
LoadModule rewrite_module modules/mod_rewrite.so
```

가 주석처리 ('#') 가 되어 있었을 것인데, 주석을 해제해 주자. 그리고 적당한 위치에

```
<VirtualHost *:80>
    ServerName localhost
    DocumentRoot {Laravel프로젝트경로/public}

    <Directory {Laravel프로젝트경로/public}>
      <IfModule mod_rewrite.c>
      Options -MultiViews
      RewriteRule ^(.*)/$ /$1 [L,R=301]

    # Handle Front Controller...
    RewriteCond %{REQUEST_FILENAME} !-d
    RewriteCond %{REQUEST_FILENAME} !-f
    RewriteRule ^ index.php [L]
      </IfModule>
	AllowOverride All
	Require all granted
    </Directory>
</VirtualHost>
```

를 추가해주자. ServerName localhost는 알아서 변경하면 된다. 나 같은 경우에 이렇게 설정을 하고 Apache를 실행한 뒤 브라우저에서 `localhost`만 입력하면 내 라라벨 맨 첫 페이지로 이동하고 라우팅도 제대로 동작하는 것을 볼 수 있었다.

---

### 참조

1. https://tomelliott.com/php/mod_rewrite-windows-apache-url-rewriting