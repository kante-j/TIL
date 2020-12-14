# HTTP 쿠키 & 세션

2020 12 01

### 개요

HTTP 쿠키는 서버가 웹 브라우저로 전송하는 작은 데이터 조각이다. 웹 브라우저는 이 조각을 저장했다가, 동일한 서버에 다시 요청을 할 때 이 쿠키를 같이 전송해준다. 따라서 서버에서 어떤 요청이 브라우저에서 들어왔는지를 판단할 때 사용하기도 한다. 

쿠키는 세 가지 목적에서 사용된다.

- **세션 관리** : 서버에 저장해야할 로그인, 장바구니 등 정보 관리
- **개인화** : 사용자 선호, 테마, 추천 등
- **트래킹** : 사용자 행동 기록 및 분석

---

### 쿠키 동작 방식

![Image for post](https://miro.medium.com/max/1060/1*fWfKsO9P2rReNzJM2doBhQ.png)

1. 클라이언트가 서버에 로그인 요청
2. 서버는 요청을 처리해서 응답 헤더에 set-cookie를 추가해서 응답.
3. 클라이언트는 그 다음부터 서버에 요청할 때, 쿠키를 헤더에 추가하여 요청
4. 서버는 쿠키를 보고 클라이언트에 응답.

```http
HTTP/1.0 200 OK
Content-type: text/html
Set-Cookie: yummy_cookie=choco
Set-Cookie: tasty_cookie=strawberry

[page content]
```

이렇게 서버에서 클라이언트에 쿠키를 저장하라고 전달하면, 클라이언트는는

```http
GET /sample_page.html HTTP/1.1
Host: www.example.org
Cookie: yummy_cookie=choco; tasty_cookie=strawberry
```

이렇게 Cookie header를 사용하여 서버로 이전에 저장했던 모든 쿠키들을 회신할 수 있다.

---

### 세션(Session)

인증을 여러 번 하지 않는 이유 중 하나가 보안에 취약하다는 점 때문이다. 클라이언트가 서버로 "나 인증할테니 쿠키 줘"를 여러 번 하면 개인 정보를 보내야 하는데, 이 과정에서 탈취가 일어날 수도 있기 때문이다. 이를 위해 **세션(Session)**을 사용한다.

세션은 일정 시간 동안, 같은 사용자 상태를 일정하게 유지시키는 기술이다. 웹 서버가 세션 아이디 파일을 만들어 서비스가 돌아가고 있는 서버에 저장하는 것이다. 서버에 저장되기 때문에 사용자 정보를 노출하지 않을 수 있다. 

![Image for post](https://miro.medium.com/max/1122/1*oiHghHg3sQW5ynmMCAtPAA.png)

1. 클라이언트는 서버로 http 요청을 한다.
2. 서버는 접근한 클라이언트의 쿠키를 확인해서, 클라이언트가 해당 SessionId를 보내왔는지 확인한다.
3. 만일 보내지 않았으면, 서버는 새롭게 SessionId를 생성해서, 클라이언트에게 set-cookie값으로 SessionId를 보낸다.
4. 그 다음부터 요청을 할 때, 전달받은 SessionId 쿠키를 자동으로 헤더에 추가해서 요청을 한다.
5. 요청헤더의 SessionId값을 저장된 세션저장소에서 찾아보고 유효한지 확인 후에 요청을 처리하고 응답해준다.

---

### 차이점

|          | 쿠키                      | 세션                                          |
| -------- | ------------------------- | --------------------------------------------- |
| 저장위치 | 로컬                      | 서버                                          |
| 보안     | 탈취, 변조 가능           | 서버에 저장되어 상대적으로 안전               |
| 생명주기 | 브라우저 종료해도 남음    | 브라우저 종료시 세션 삭제                     |
| 속도     | 파일에서 읽기 때문에 빠름 | 요청마다 서버에서 처리를 해야하기 때문에 느림 |

---

보면 좋은 글이 있어 첨부

https://velog.io/@junhok82/%EB%A1%9C%EA%B7%B8%EC%9D%B8%EC%9D%80-%EC%96%B4%EB%96%BB%EA%B2%8C-%EC%9D%B4%EB%A3%A8%EC%96%B4%EC%A7%88%EA%B9%8CCookie-Session

---

참조

1. https://chrisjune-13837.medium.com/web-%EC%BF%A0%ED%82%A4-%EC%84%B8%EC%85%98%EC%9D%B4%EB%9E%80-aa6bcb327582
2. https://developer.mozilla.org/ko/docs/Web/HTTP/Cookies
3. https://velog.io/@junhok82/%EB%A1%9C%EA%B7%B8%EC%9D%B8%EC%9D%80-%EC%96%B4%EB%96%BB%EA%B2%8C-%EC%9D%B4%EB%A3%A8%EC%96%B4%EC%A7%88%EA%B9%8CCookie-Session