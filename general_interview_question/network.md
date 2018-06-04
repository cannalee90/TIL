### HTTP method에 대해서 설명해보시오

- GET: 가장 많이 사용되는 메서드이다. 서버에서 특정 리소스를 요청할때 쓰입니다. url로 어떤 리소스를 요청하는지 표현합니다. CRUD에서 R에 해당됩니다.
- POST: 클라이언트에서 서버로 데이터를 보낼때 사용합니다. reqeust body에 데이터가 저장되는 형태로 HTTP request를 만들게 됩니다. CRUD에서 C, U, D를 할때 쓰이기도 합니다. POST request는 non-idempont합니다.
- PUT: POST와 비슷하게, 리소스를 새로 만들거나 수정하는 request에 사용됩니다. POST request와 차이점은 PUT request는 idempotent이다.
- DELETE: 리소스를 삭제할때 쓰이는 메서드이다. 
- PATCH: PUT과 비슷하지만, 리소스의 일부를 수정할때 주로 사용하는 메서드입니다. 또한 PATCH request는 POST request와 같이 non-idempotent합니다.
- HEAD: HEAD 메서드는 GET과 거의 비슷하지만, response-body를 받지 않습니다. 주로 GET request를 보내기 전에 어떤 GET request가 오는지 확인해보는 용도로 주로 쓰입니다.
- OPTIONS: OPTIONS request는 특정 url이 어떤 메서드와 오퍼레이션을 지원하는지에 대한 데이터를 받아야 합니다.

idempotent: 같은 요청을 여러번 해도 같은 결과를 만들어 내는 것.



https://assertible.com/blog/7-http-methods-every-web-developer-should-know-and-how-to-test-them
https://softwareengineering.stackexchange.com/questions/114156/why-are-there-are-no-put-and-delete-methods-on-html-forms

### http 1.1에서 host가 추가되면서 할 수 있는일

만약 한개의 IP주소를 가진 컴퓨터에서 여러개의 DNS를 가진 웹서버를 호스팅 하거나, host를 사용해서 요청을 구분해 낼 수 있다. 

https://stackoverflow.com/questions/43156023/what-is-http-host-header
https://docs.oracle.com/cd/E40518_01/studio.310/studio_install/src/cidi_studio_reverse_proxy_preserve_host_headers.html

### HTTP GET과 POST 비교

GET은 요청하는 데이터 `HTTP Request Message`가 url에 담겨서 전송되기 때문에, 보안상에 이슈가 있고 데이터의 크기가 제한적이다. POST 방식의 request는 `HTTP Message의 Body` 부분에 데이터가 담겨서 전송된다. 또한 GET 방식의 요청은 브라우저에서 캐슁될 수 있다. 이름이 같을 경우 잘못된 정적 파일을 로딩하기 때문에 파일명 뒤에 해쉬값을 추가해서 이러한 문제를 해결한다.

### 3way handshake

### TCP와 UDP의 비교

#### UDP

User Datagram Protocol은 비연결형 프로토콜이다. UDP는 흐름제어, 오류제어 또는 손상된 세그먼트의 수신에 대한 재전송을 하지 않는다. 요청에 대한 응답이 보장되지 않고 순서 역시 보장되지 않는다. 코드가 간단할 뿐만 아니라 초기설정에서 적은 메세지가 요구된다.

#### TCP

대부분의 경우 사용되는 프로토콜이다. Transmission Control Protcol은 신뢰성 있는 바이트 스트림을 전송하도록 설계되었다. TCP 서비스는 송신자와 수신자 모두 소켓을 생성함으로써 이루어지고, 연결 설정은 3-way-handshake를 통해 행해진다. 멀티캐스팅이나 브로드캐스팅을 지원하지 않는다.



https://d2.naver.com/helloworld/47667


### TCP STATE

1. LISTEN: 상대편 TCP로부터 연결 오청을 기다림
2. SYN_SENT: SOCKET을 이용해 생선하는 경우로 소켓을 연 으용 프로그램을 대신해 TCP가 SYN을 전송하고 연결을 완료 할 수 있도록 상대 응답을 기다림
3. SYN_RECV:  이전에 LISTEN상태에 있던 TCP가 SYN을 수신해 SYN/ACK를 응답으로 전송 한 뒤 다음 연결을 완료 할 수 있도록 상대 TCP로부터 ACK기다림
4. ESTABLISHED:  상대편 TCP와의 연결 수립을 완료. 이제 두 TCP간 데이터 세그먼트를 주고 받을 수 있다.
5. FIN_WAIT1: 응용 프로그램에서 연결을 닫음. 상대 TCP의 연결을 종료하도록 FIN을 전송하고 ACK를 기다림.
6. FIN_WAIT2:  FIN_WAIT1 상태에 잇던 TCP가 상대편 TCP로부터 ACK를 수신
7. CLOSING:  FIN_WAIT1 상태에서 ACK를 기다리던 TCP가 ACK가 아닌 FIN을 수신. 상대방 TCP에서도 종료를 수행 했을 경우 발생.
8. TIME_WAIT:  FIN을 수신한 TCP는 연결이 안정적으로 종료 되고 네트워크 상에 잔존하는 중복 세그먼트가 만료 될 수 있도록  TIME_WAIT상태에서 정해진 시간 동안 대기 한다. 정해진 시간이 지나면 연결이 종료되며 관련 커널 자원도 해제 한다.
9. CLOSE_WAIT: 상대편 TCP로부터 FIN을 수신 했다.
10. 기존에 CLOSE_WAIT 상태에 있던 TCP는 상대편 TCP로 FIN을 전송 한 뒤 ACK를 기다린다. ACK를 수신하면 연결이 종료되며 커널 자원이 해제 된다. 
