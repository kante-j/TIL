# Apache 원리

윈도우에서 Apache를 설치하고.. Django나 Nodejs 애플리케이션을 Apache로 실행을 하면 잘 동작은 한다.. 그런데 따로 python manage.py runserver나 npm start를 해주지 않아도 알아서 서버 내부를 통해 데이터를 받아오고, 동작을 하는데 왜 이러지? 한 번 알아봐야겠다.

---

### Apache란?

- Http Server로, 웹 서버이다. 리눅스, 유닉스 , MS Windows, 등등 에서도 운영이 가능하다.
- 톰캣, Resin 등 WAS와 같이 사용이 가능하다.
- https로 보안을 강화할 수 있다.
-  /etc/httpd/conf/httpd.conf  또는 /etc/apache2/apache2.conf 로 설정을 한다.

---

### Web Server vs WAS



|      | Web Server                                                   | WAS                                                          |
| ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 개념 | 하드웨어 : Web서버가 설치된 컴퓨터<br />소프트웨어 : HTTP 요청을 받아 정적인 컨텐츠를 제공하는 프로그램 | DB 조회, 로직 처리 등 동적인 컨텐츠를 제공하는 프로그램      |
| 기능 | HTTP 프로토콜을 기반으로, 클라이언트의 요청을 서비스<br />정적인 컨텐츠 제공<br />동적인 컨텐츠 제공을 위한 요청 전달 | Web Server+Web Container<br />DB 접속기능<br />트랜잭션 관리 기능 |
| 예시 | Apache, Nginx, IIS                                           | Tomcat, Jeus                                                 |

---

### Why Apache? Nginx? 

웹  서버는 인터넷에서 클라이언트 / 사용자에게 요청 / 페이지를 전달하기위한 기본이다

웹 프레임워크는 웹 서버를 사용하여 클라이언트에 요청을 전달하지만 웹 서버는 아니다.

그렇다면 왜 아파치나 엔진엑스로 구현을 하나? 그냥 `npm start` 하면 되는데.

```
DO NOT USE THIS SERVER IN A PRODUCTION SETTING. It has not gone through security audits or performance tests. (We’re in the business of making Web frameworks, not Web servers, so improving this server to be able to handle a production environment is outside the scope of Django.)
```

장고에서 python managy.py runserver로 prod 환경에서 실행을 하면 이런 경고가 뜬다. 장고는 Web server긴 하지만 동시에 Web Framework여서, 단순히 개발을 편리하게 만들어 주는 것으로 사용하고, 배포는 Apache나 Nginx같은 Web server로 배포를 하는 게 좋다. 

`npm start` 나 `python manage.py runserver`로 배포를 하면, 오류가 났을 경우에 서버가 멈추기 쉽상이지만, nginx나 apache로 서버를 배포하면 다른 프로세스를 생성하여 서버를 운용하므로, 한 프로세스가 문제가 조금 있어도 서버는 문제없이 돌아간다.