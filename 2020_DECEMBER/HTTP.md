# HTTP

2020 12 02

Cookie와 Session을 공부하면서 계속 모르는 용어들이 나오고, HTTP에 대해서 조금 깊게 공부해야겠다고 느꼈다. 네트워크를 공부하면서 맨 처음에 가장 이해가 가지 않았던 것이, OSI 7 계층에서 같은 레이어끼리 정보를 주고받는데, 그 정보는 맨 하위 레이어로 내려간대.. 이게 뭔말일까.. 싶었는데 최근에 이해가 가면서 학습에 속도가 붙은 것 같다. HTTP는 웹 개발자라면 무조건적으로 알아야할 내용이다.

---

### 개요

#### Hyper Text Transfer Protocol

>  www상에서 정보를 주고받을 수 있는 프로토콜이다. 주로 HTML 문서를 주고받는 데에 쓰인다. 주로 TCP를 사용하고 HTTP/3 부터는 UDP(QUIC)을 사용하며, 80번 포트를 사용한다

- HTTP는 클라이언트와 서버 사이에 이루어지는 요청/응답 프로토콜
- 클라이언트인 웹브라우저가 HTTP를 통하여 서버로부터 웹페이지(HTML)나 그림 정보를 요청하면, 서버는 이 요청에 응답하여 필요한 정보를 해당 사용자에게 전달하게 된다.
- TCP/IP를 이용하는 Application Layer 프로토콜
- HTTP는 연결 상태를 유지하지 않는 비연결성 프로토콜 -> Cookie와 Session이 등장.

![image](https://user-images.githubusercontent.com/28242038/100829070-d9018080-34a3-11eb-9f7c-fe9337a355ea.png)

네이버로 들어가서 크롬 개발자모드를 켜고 Application에 들어가면 Cookies나 여러 가지를 볼 수 있기도 하다.

#### 요청 메시지

클라이언트와 서버 사이 소통은 평문(ASCII) 메시지로 이루어진다. 클라이언트가 서버로 보내는 요청 메시지는 다음과 같다.

- 요청 내용
  - GET /images/logo.gif HTTP/1.1
- 헤더
  - Accept-Language: en
- 빈 줄
- 기타 메시지

등을 포함하여 요청메세지를 보내며, 요청 내용과 헤더는 CRLF로 끝나야 한다.

#### 응답 메시지

- 상태표시 행(Status Line): 상태 코드와 reason message를 포함한다.
  - HTTP/1.1 200 OK
- 응답 헤더 필드
  - Contenty-Type: text/html

- HTTP 상태 코드는 IANA에서 관리를 하고 있다. 
  - http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml

---

### HTTP 진화

#### 1. HTTP/0.9 - 원라인 프로토콜

- HTTP 초기 버전에는 버전 번호가 없었다.

- 요청은 단일 라인으로 구성되며, 리소스에 대한 경로로 GET 메서드만 가능

  ```http
  GET /login.html
  ```

- 응답  또한 파일 내용 자체로 구성되었다.

#### 2. HTTP/1.0 - 확장성

- 버전 정보가 요청에 같이 전송됨

- Status 코드 또한 응답의 시작 부분에 붙어 전송 -> 요청에 대한 성공/실패 결과를 알 수 있었음

- 평범한 HTML 파일 외에 json, text 등 다른 문서들을 전송하는 기능 추가

  ```http
  GET /login.html HTTP/1.0
  User-Agent: NCSA_Mosaic/2.0
  
  200 OK
  Date: Thu, 20 Dec 1995 09:22:11 GMT
  Server: ...
  ...
  ```

#### 3. HTTP/1.1 - 표준

1995년 부터 다양한 HTTP/1.0 구현이 진행되고, 1996년 까지 표준화가 진행중에 있었는데, HTTP의 첫 번째 표준인 HTTP/1.1은 HTTP/1.0이 나온지 몇 달 되지 않은 1997년 초에 공개되었다.

- 한 Connection 당 하나의 요청을 처리하도록 설계가 됨. 하지만 재사용될 수 있게 하여, 사용된 커넥션을 다시 열어 시간을 절약하게 함
- 파이프라이닝을 추가하여, 첫 번째 요청에 대한 응답이 전송되기 전, 두 번째 요청 전송을 가능하게 함.
- 캐시 제어 메커니즘 도입
- Host 헤더 덕분에, 동일 IP 주소에 다른 도메인을 호스트하는 기능이 서버 코로케이션을 가능하게 함.
  - **코로케이션**의 사전적 의미는 직접 서버를 관리를 하지 않고 인터넷 서비스를 제공하는 IDC 업체가 보유한 초고속 네트워크 망으로 서버를 연결하여 관리하는 서비스



그 후 15년 넘게 HTTP/1.1은 매우 안정성을 유지해 왔다.

1.**보안 전송을 위한 HTTP**

- TCP/IP 스택을 통해 HTTP를 전송하는 대신에 SSL을 추가해서 HTTPS라는 프로토콜 개발
- SSL -> TLS로 됨

2.**복잡한 애플리케이션을 위한 HTTP**

- REST API 패턴이 2000년도에 고안됨.
- API에 의해 유도되는 액션들은 기초적인 HTTP 메서드를 이용한 특정 URI 접근에 의해서도 전달되지 않음.

3.**웹의 보안 모델**

- CORS, CSP 등
- [Same origin 정책](https://developer.mozilla.org/ko/docs/Web/Security/Same-origin_policy)

#### 4. HTTP/2.0 - 더 나은 성능을 위한 프로토콜

HTTP/1.1 커넥션은 올바른 순서로 전송되는 요청을 필요로 한다. 많은 양의 오버헤드와 복잡도가 남아 있다. 2010년 초에 구글은 SPDY 프로토콜을 구현하여, 클라이언트와 서버 간의 데이터 교환을 대체할 수단을 만들었다.

- 최적화 기술 구현

- 동일한 Connection 상에서 병렬 요청 가능. (Multiplexed Streams)

  - 한 커넥션으로 동시에 여러 개의 메세지 주고받음.

  - 응답 순서는 상관 없음.

    ![img](https://t1.daumcdn.net/cfile/tistory/9903B4455BE1592C10)

- 순서 제거(Stream Prioritization)

  - 리소스간 의존관계 (우선순위 설정)

- 클라이언트 캐시를 서버 푸쉬라고 불리는 매커니즘으로 필요하게 될 데이터로 채워넣도록 허용.

  ![img](https://t1.daumcdn.net/cfile/tistory/99A8B5395BE159C136)

  

2015년 5월에 표준화가 되었고, 큰 성공을 거두었다.

---

### HTTP/1.1 단점

1. HOL Blocking
   - 첫 번째 요청에 대한 응답이 지연되면 다음번째 요청에 대한 응답은 첫 번째 응답처리가 완료되기 전까지 대기
2. RTT 증가
   - 하나의 Connection에 하나의 요청을 처리하기 때문에 매 요청별로 Connection을 만들게 됨
   - 3way handshake가 반복적으로 일어나고, 불필요한 RTT 증가와 네트워크 지연을 초래하여 성능을 저하 시킴
3. 무거운 Header 구조
   - 매 요청마다 중복된 Header 값 전송
   - Domain에 설정된 cookie 정보도 매 요청마다 헤더에 포함하여 전송

---

### HTTP/3.0 & QUIC

HTTP 3 에 대한 내용과 QUIC 에 대한 내용은 다음 번에 큰 주제로 다뤄 볼까 한다. 내가 학교 과목 중에 하나에서 QUIC으로 NS-3에서 시뮬레이션을 돌리는 작업을 하면서 QUIC을 공부하긴 했지만 다시 공부해 보는 것도 좋을 것 같다.

---

참조

1. https://ko.wikipedia.org/wiki/HTTP
2. https://developer.mozilla.org/ko/docs/Web/HTTP/Basics_of_HTTP/Evolution_of_HTTP
3. https://developers.google.com/web/fundamentals/performance/http2/?hl=ko