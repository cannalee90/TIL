##Controller
  - Controller Code는 최대한 심플하게 작성되어야 하고 정해진 blueprint를 따라야 한다
  - Better Controller implementation [참고](http://www.naver.com)하기
  - 모든 컨트롤러의 액션은 하나의 모델만을 바꿔야 한다. 만약 여러개 모델을 바꾸거나 수정해야 될 작업은 반드시 모델 안에서 이루어져야 함
  - 컨트롤러가 반드시 해야할 이슈들
    1. 보안
    2. Parsing and white-list parmeters
    3. Loading or instantiating the model
    4. Deciding which view to render
  - ResourceController를 상속받으면 7개의 restful action이 그냥 생기지만 큰 프로젝트로 넘어가면 복잡해짐 ㄴㄴㄴ 염

##ActiveRecord Learning
  - ActiveRecord를 사용해서 구현하면 편한 것들
    - validataion of data entered by user
    - Form roundtrip(잘못 입력한 데이터들 edit)
    - LifeCycle callback
  - Make it hard to miuse your model
  - Never rely on other code to use the custom model methods that you provide. To enforce an API in ActiveRecord, you must express it in validations and callbacks.

##ActiveModel
  - 액티브레코드는 많은 편의성을 제공해준다. 특히 form을 렌더링할때 invalid한 value들을 다 치울수 가 있어서..
  - 특히 테이블에 insert되지 않더라도 그런 귀찮은것들을 한꺼번에 처리해줄 수 있음
  - 다시 한번 공부해볼껄 ActiveType을 사용하면 slim-controller Fat-model을 잘 따라갈 수 잇따.
  - Inheritance를 잘 사용해서 모델을 만들어야 한다.
  - 코드가 복잡해지면 object를 잘 나누어서 사용해야 합니당..
