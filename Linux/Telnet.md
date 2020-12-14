# Telnet으로 Memcached 정보 조회하기

2020 12 08

Memcached 서비스를 조회할 때 기본적으로 프로그래밍 언어로 외부 라이브러리를 사용해서 할 수도 있다. 하지만 가장 Raw하게 조회하려면 리눅스에서 Memcached Server로 붙어서 조회를 할 수도 있었다. 로컬 서버에 Memcached 서버를 설치하고 여기에 접속하는데, 이 때 사용하는 것이 Telnet이었다. ssh로도 접속할 수 있었지만 간편한 telnet을 사용했다. 텔넷은 또 어떤 것들에 사용할 수 있는지, 특징은 어떤게 있는지 알아보자. 

---

### Telnet 개요

> **텔넷** 은 인터넷이나 로컬 영역 네트워크 연결에 쓰는 네트워크 프로토콜이다.

- telnet이라는 용어는 프로토콜의 클라이언트 일부 기능이 추가된 소프트웨어를 일컫는다. 
- UNIX 시스템에서 대부분 사용 가능하다.
- TCP/IP 스택을 갖춘 네트워크 장비와 운영체제들은 몇가지 종류의 텔넷 서비스를 지원한다.
- telnet의 보안 문제 때문에 SSH로 대체되기도 하였다.

Windows에서 원격 데스크톱 연결 같은 것이 Telnet으로 보면 된다.

리눅스에서 텔넷으로 접속하는 명령어는 다음과 같다

```bash
$ telnet {ip주소} {port번호}
```

#### Telnet 기능

- 유닉스 명령어 사용
  - 관리용 ID / Password 변경
  - 메일 변경
  - 파일 권한 변경
  - 디렉터리 관리
- CGI 프로그램
  - 게시판, 방명록 등의 CGI 프로그램
  - 프로그램 작업을 위한 작업
- 네트워크
  - 다른 곳의로의 접속
  - ping 테스트



### Telnet vs ssh

- 텔넷은 정보를 Byte스트림 형식으로 주고받음
- SSH는 DES, RSA 등 고급 암호화로 통신함, 압축기술을 가용해 트래픽이 텔넷보다 크게 늘어나지 않음.

-> 정보가 누출될 수 있는 텔넷보다 어느 정도 정보노출 위험이 적어 SSH를 많이 사용 한다.

---

#### 텔넷으로 Memcached 서버 접속했을 때 사용가능한 명령어

| Command              | Description                                                  | Example                                                      |
| -------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| get                  | Reads a value                                                | `get mykey`                                                  |
| set                  | Set a key unconditionally                                    | `set mykey <flags> <ttl> <size>`  <p>Ensure to use \r\n als line breaks when using Unix CLI tools. For example</p> `printf "set mykey 0 60 4\r\ndata\r\n" \| nc localhost 11211` |
| add                  | Add a new key                                                | `add newkey 0 60 5`                                          |
| replace              | Overwrite existing key                                       | `replace key 0 60 5`                                         |
| append               | Append data to existing key                                  | `append key 0 60 15`                                         |
| prepend              | Prepend data to existing key                                 | `prepend key 0 60 15`                                        |
| incr                 | Increments numerical key value by given number               | `incr mykey 2`                                               |
| decr                 | Decrements numerical key value by given number               | `decr mykey 5`                                               |
| delete               | Deletes an existing key                                      | `delete mykey`                                               |
| flush_all            | Invalidate all items immediately                             | `flush_all`                                                  |
| flush_all            | Invalidate all items in n seconds                            | `flush_all 900`                                              |
| stats                | Prints general statistics                                    | `stats`                                                      |
|                      | Prints memory statistics                                     | `stats slabs`                                                |
|                      | Print higher level allocation statistics                     | `stats malloc`                                               |
|                      | Print info on items                                          | `stats items`                                                |
|                      |                                                              | `stats detail`                                               |
|                      |                                                              | `stats sizes`                                                |
|                      | Resets statistics counters                                   | `stats reset`                                                |
| lru_crawler metadump | Dump (most of) the metadata for (all of) the items in the cache | `lru_crawler metadump all`                                   |
| version              | Prints server version.                                       | `version`                                                    |
| verbosity            | Increases log level                                          | `verbosity`                                                  |
| quit                 | Terminate session                                            | `quit`                                                       |



따라서 telnet으로 Memcached 정보를 조회하려면

```bash
$ telnet localhost 11211
Trying ::1...
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.


stats
... (생략)
STAT bytes 196606
STAT curr_items 67
STAT total_items 210
STAT evictions 0
STAT reclaimed 0
END

quit
Connection closed by foreign host.
```

이런식으로 하면 된다.

---

### 참조

1. https://ko.wikipedia.org/wiki/%ED%85%94%EB%84%B7
2. https://lzone.de/cheat-sheet/memcached