- primitive type
    - Number, String, Boolean, null, undefined
    - it is stored in stack
    - 변수가 값을 직접적으로 가르킨다
    - 그 자체가 하나의 값을 나타낸다.
    - call by value
- reference type
    - primitive 타입이 아닌 모든 것들을 객체라 칭한다. 
    - 힙 메모리에 저장된다
    - 변수가 가르키는 곳이 포인터로써, 참조값임
    - call by reference

- 느슨한 타입 언어
    - 변수를 선언할때 타입을 설정하지 않음. 
- Number
    - 정수와 실수의 구분이 없다.
- String
    - 한 번 정의된 문자열은 변하지 않는다. 새롭게 값을 할당하는 것만 가능.
- Null, Undefined
    - 두 값 모두 값이 비어있음을 나타냄.
    - 자바스크립트 환경 내에서 기본적으로 값이 할당되지 않으면 undefined 타입이고, undefined 타입의 변수는 변수 자체의 값 또한 undefined이다.
    - null 타입 변수의 경우는 개발자가 명시적으로 값이 비어있음을 나타낸다. 타입은 object

- 하나의 객체는 여래기의 프로퍼티들을 포함하고, 각각의 프로퍼티는 기본 값을 가지거나, 다른 객체를 가르킬 수 있다. 

객체 생성 방법
- Object 생성자 함수 이용
- 객체 리터럴 방식 이용
- 생성자 함수 이용
- class 키워드를 사용한 방법
- 모든 객체는 부모역활을 하는 프로토타입 객체를 가르키는 숨겨진 프로퍼티가 있다.


자바스크립트에서는 배열도 객체이다
- object prototype을 부모로 가진다.
- index값 말고도 다른 프로퍼티에 값을 가질 수 있다.
- 배열의 length 속성은 가장 큰 인덱스 값에 + 1을 더한값을 출력한다. 
- Object.prototype < Array.prototype < 배열
- Object.prototype < 객체

typeof 연산자를 피연산자의 타입을 `문자열` 형태로 리턴한다. 주의할점은 null과 배열은 'object'를 리턴하고 함수는 'function'을 리턴한다.

!! 연산자는 피연산자를 boolean 값으로 리턴한다.


참조
- https://stackoverflow.com/questions/13266616/primitive-value-vs-reference-value
- https://bestalign.github.io/2015/10/21/understanding-loose-typing-in-javascript/
- https://medium.com/javascript-scene/master-the-javascript-interview-what-s-the-difference-between-class-prototypal-inheritance-e4cd0a7562e9
- https://blog.kevinchisholm.com/javascript/difference-between-object-literal-and-instance-object/

