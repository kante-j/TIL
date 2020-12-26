# Nginx란

2020 12 24

보통 대학생때 프로젝트를 하고 서버를 개발한다고 한다면 그냥 로컬에 개발하거나, AWS에 올려도 Django 일 경우 `python manage.py runserver` 로 서버를 실행시키거나 Node.js 일 경우 `npm start` 로 서버를 실행하는 경우가 대다수이다.

그래서 주소창에 보면 http://{IP주소}:8000 과 같이 포트번호가 있는 경우가 대부분이다. 도메인을 구매해도 되지만, nginx 같은 걸로 포트포워딩을 해 줄 수도 있다.

그렇다면 nginx란 뭘까? 차근차근 알아보도록 하자.

---

### 개요

> 트래픽이 많은 웹사이트를 위해 설계한 Async Event-Driven 구조의 서비스.

따라서 적은 자원으로 빠르게 서비스를 사용자에게 제공해줄 수 있다. Apache의 C10K 문제를 해결하기 위해서 만들었다. C10K는 하나의 Web Server에 10000개의 동시 접속을 다룰 수 있는 문제를 말한다.

---

### Apache vs Nginx

| Apache                            | Nginx                         |
| --------------------------------- | ----------------------------- |
| 요청 하나당 쓰레드 하나가 처리.   | 비동기 Event-Driven           |
| 사용자가 많으면 많은 쓰레드 생성  | 다수의 연결을 효과적으로 처리 |
| 하나의 쓰레드 = 하나의 클라이언트 | 리소스를 적게먹음             |

#### 쓰레드 vs Event Driven

![image](https://user-images.githubusercontent.com/28242038/103152744-40260280-47ce-11eb-8e93-3fd8146e4f60.png)

![image](https://user-images.githubusercontent.com/28242038/103152749-474d1080-47ce-11eb-9290-9568c4d54844.png)

위에가 쓰레드 방식이고 아래가 Event Driven 방식이다. 쓰레드 방식은 하나의 커넥션에 하나의 쓰레드가 생성되고, Event Driven은 먼저 처리되는 것부터 진행되도록 하는 방식이다.

---

### Nginx 프록시 서버

node.js 에서 Express로 서버를 구성하고 Nginx로 프록시 서버로 구성해보자.

```javascript
const express = require('express');
const app = express();
app.get('/', function(res =>{
			res.send("Hello World!");
})
app.listen(3000);
```

그리고 nginx.conf 파일에다가

```nginx
server{
  listen 	80;
  server_name localhost;
  location{
    proxy_pass http://127.0.0.1:3000/;
  }
}
```

으로 설정을 한다.

그러면 인터넷 웹페이지에 127.0.0.1로 접속을 하면 3000번 포트로 접속이 된다.

이유는 클라이언트에서는 80포트로만 요청이 들어오는데, 요청을 8080, 8081 등 여러 Application Server로 보내줄 수 있다.



Nginx 변수도 처리할 수 있다

```
$host : opentutorials.org
$uri : /production/module/index.php
$args : type=module&id=12
server_addr : 115.68.24.88
server_name : localhost
server_port : 80
server_protocol : HTTP/1.1
$arg_type : module
$request_uri : /production/module/index.php?type=module&id=12
$request_filename : /usr/local/nginx/html/production/module/index.php
```



---

### Linux도 Nginx 설치할 수 있다.

https://whatisthenext.tistory.com/123

---

### 참조

https://m.blog.naver.com/jhc9639/220967352282

https://wan-blog.tistory.com/54