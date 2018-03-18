자바스크립트에서 함수를 생서하는 방법은 3가지가 있다. 모든 함수는 Fuction()이라는 기본 내장 생성자 함수로부터 생성된 객체이다.

- 함수 선언문
    - 함수명이 정의 되어야 한다.
    - 함수 호이스팅이 일어난다.(함수 선언문 형태로 정의한 함수의 유효 범위는 코드의 맨 처음부터 시작되는 것, 즉 함수를 나중에 선언해도 사용할 수 있다는 것.)

- 함수 표현식
    - 더글러스 아저씨가 추천하는 방식
    - 함수명 없이 생성한 익명함수를 변수에 할당하는 방식
    - 만약 함수 표현식으로 함수를 생성할때, 함수명을 포함시켜도 외부에서는 그 함수명으로 호출 할 수 없다

```
const a = function add(a, b) {
    return a + b;
}

a(1,2)
> 3

add(1,2)
> Uncaught ReferenceError: add is not defined
```

    - 함수 이름을 잘 이용하면 함수 코드 내부에서 함수 이름으로 함수의 재귀적인 호출 처리가 가능하다.

```
var factorialVar = function factorial(n) {
    if(n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

console.log(factorialVar(3))
> 6
console.log(factorial(3));
>
```

- Function() 생성자 함수

자바스크립트에서 함수 리터럴은 네가지 부분으로 구성된다.

- function keyward
- 함수명
- 매개변수 리스트
- 함수 몸체

자바스크립트에서는 함수도 객체이다. 일반 객체처럼 프로퍼티를 가질 수 있고 아래와 같은 동작이 가능하다. 따라서 자바스클비트에서는 함수를 일급 객체라고 한다.

- 리터럴에 의해 생성
- 변수나 배열의 요소, 객체의 프로퍼티 등에 할당 가능.(함수)
- 함수의 인자로 전달 가능.(함수)
- 하뭇의 리턴값으로 리턴 가능.(함수)
- 동적으로 프로퍼티를 생성 및 할당 가능
- [1급 객체](https://bestalign.github.io/2015/10/18/first-class-object/)
- [MDN JS](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions)

자바스크립트에서 함수는 모두 `arguments`, `caller`, `name`, `prototype`, `__proto__`, `length` 등등의 함수를 가지고 있다.

1. length
    - 함수가 정상적으로 실행될때 기대되는 인자의 갯수(parameter)의 갯수를 말한다

```
function Person(name, age) {};
console.log(Person)
> 2
```

2. arguments 객체
    - 정의된 함수의 인식보다 더 적게 함수를 호출할 경우 인자에는 undefined 값이 정의되고, 초과된 인수는 무시된다.
    - 런타임에서 호출된 인자의 갯수를 확인 할 수 있게 도와준다
    - 유사 배열 객체이다(`[]`로 접근 가능하지만 Array.prototype.forEach와 같은 배열 전용 함수는 사용이 불가능하다.)
    - 런타임에 호출된 인자들을 순서대로 인덱스로 접근 할 수 있게 된다
    - 함수를 호출할대 임수들과 함께 암묵적으로 `arguments` 객체가 함수 내부로 전달된다.
    - 배열 메서드를 사용할 경우 에러가 발생한다
3. callee 프로퍼티
    - 현재 실행죽인 함수의 참조값


함수의 여러가지 형태

- callback
    - 익명함수의 대표적인 용도
    - 코드를 통해 명시적으로 호출하지 않고, 어떤 이벤트나 특정 시점에 도달했을때 시스템에서 호출되는 함수를 말한다. 또한 인자로 넘겨서, 코드 내부에서 호출되는 함수도 콜백 함수라고 할 수 있다. 
- 즉시 실행 함수
    - 함수를 정의함과 동시에 즉시 실행하는 함수를 말한다.
    - 함수 리터럴을 `()`로 둘러 싸고 즉시 실행할 수 있도록 끝에 `()`를 추가해서 바로 호출한다. 이때 괄호안에 매개변수를 넘겨줄수 있다.
    - 이렇게 만들어진 함수인 경우 같은 함수를 다시 호출 할 수 없다.
    - jQuery나 프레임워크 소스들의 형태이다.(네임스페이스를 해치지 않음)
    - 이렇게 될 경우 함수 외부에서 함수 내부의 변수나 함수에 접근할 수 없다.

```
(fucntion (name) {

})('foo')
```

- 내부 함수
    - 내부 함수에서는 자신을 둘러싼 부모 함수의 변수에 접근이 가능하다.
    - 함수 내부에서 선언된 변수는 함수 외부에서 접근이 불가능하다. 또한 부모 함수 외부에서 내부 함수를 호출 하는 것을 불가능하다.
    - 함수 외부에서도 특정 함수 스코프 안에 선언된 내부 함수를 호출 할 수 있는 방법은 부모 함수에서 내부함수를 외부로 리턴하면 가능하다.

```
function parent() {
    var a = 10;;
    var child = function() {
        console.log(a);
    }

    return child;
}


var inner = parent();
inner();

```

** 부모 함수 스코프의 변수를 참조하는 함수를 클로저라고 한다 **

아래와 같은 예제와 같이 함수를 리턴하는 함수를 만들 수 있다.

```
var self = function() {
    console.log('a');
    return function() {
        console.log('b');
    }
}

self = self();
> a
self();
> b
```

this 바인딩

- 객체의 프로퍼티가 함수일 경우, 이 함수를 메써드라 부른다. 이러한 메써드를 호출할 때, 메서드 내부 코드에서 사용된 this는 해당 메서드를 호출한 객체로 바인딩 된다.
- 함수를 호출할때(not 메써드) 해당 함수 내부 코드에서 사용된 this는 전역 객체에 바인딩 된다. 브라우저에서 자바스크립트를 실행하는 경우 전역 객체는 window 객체가 된다.
- 이때 생기는 부작용을 극복하기 위해서 `this` 대신에 `that` 혹은 `_this`를 사용한다.
- 이러한 `this` 바인딩을 명시적으로 할 수 있도록 `call`과 `apply`와 같은 메서드를 사용한다. 또한 `jQuery`, `underscore.js`와 같은 라이브러리 들은 `bind`라는 이름의 메써드를 통해, 사용자가 원하는 객체를 `this`에 바인딩 할 수 있게 해준다.

생성자 함수(constructor)
- https://css-tricks.com/understanding-javascript-constructors/
- 비슷한 여러개의 객체를 만들때 사용한다
- (함수가 만들어질때의 동작 정리하기)

객체리터럴로 객체를 만들때와 생성자 함수로 객체를 만들때 만들어진 객체의 `__proto__` 값이 다르다.
- 객체 리터럴의 `__proto__`는 Object.prototype
- 생성자 함수로 객체를 만들면 myFunction.prototype

`__proto__`
- 자신의 부모 역활을 하는 프로토타입 객체를 가르킨다
- 일반적인 함수 객체의 부모 역활을 하는 프로토타입 객체를 Fuction.prototype, F.prototype이라고 한다.(Function.prototype의 `__proto__`는 Object.prototye)


>  모든 함수의 부모 객체는 Function.prototype의 객체이다. 그리고 Function.prototype은 함수이다. 이렇게 될 경우 Function.prototype의 `__proto__`는 Function.prototype이어야 하지만 Function.prototype의 `__proto__`는 Object.prototype을 가르키고 있다. 왜냐하면 ECMAScript의 명세서에는 예외적으로 Function.prototype의 객체 부모를 Object.prototype이라고 정의하고 있다.

`prototype`

- 이 함수가 생성자로 사용될 때 이 함수를 통해 생선된 객체의 부모 역활을 하는 프로토타입 객체를 가르킨다.
- 자바스크립트에서 함수를 생성할 때, 함수 자신과 연결된 프로토타입 객체를 통시에 생성하며, 이 둘은 다음 그림처럼 각각 prototype과 contructor 프로퍼티를 서로 참조하게 된다.

```
함수(myFunction)    프로토 타입 객체(myFunction.prototype)
prototype       ->
                <-  constructor
```

```
function myFunction () {
    return true;
}

console.dir(myFunction.prototype)

Object
    constructor : ƒ myFunction()
    __proto__ : Object
```


myFunction의 `__proto__`는 `Function.prototype`
`Function.prototype`의 `__proto__`은 `Object.prototype`

Function의 `__proto__`는 `Function.prototype`이고
Function.prototype은 `Function.prototype`이다.



생성자 함수가 동작하는 방식
1. 빈 객체 생성 및 this 바인딩
    - 생성자 함수 코드가 실행되기 전 빈 객체가 생성. 이 객체는 this로 바인딩 됨.
    - 하지만 이때 생성된 객체도 부모의 프로토타입 객체와 연결되어 있다.
2. this를 통한 프로퍼티 생성
    - 함수 코드 내부에서 this를 사용해서 프로퍼티나 매서드 생성
3. 생성된 객체 리턴
    - 리턴문이 없을 경우 this로 바인딩된 새로 생성된 객체 리턴. 명시적으로 this를 리턴해도 결과는 가다. 하지만 다른 객체를 명시적으로 리턴할 경우 다른 객체가 리턴됨.

위 사실을 알고 있으면 아래의 코드가 이해된다.

```
function A(arg) {
    if (!(this instanceof A)) {
        return new A(arg);
    }
    this.value = arg ? arg : 0;
}
```

생성자 함수를 호출할때 `new` 키워드를 붙이지 않으면 전역 객체에 바인딩된다.

`call()`과 `apply()` 메서드를 사용하면 명시적으로 `this`를 바인딩 할 수 있다.

```
function.apply(thisArg, argArray)
```

- 첫 번째로 인자로 넘긴 객체(thisArg)가 명시적으로 바인딩 되고, argArray인자는 함수를 호출할대 넘길 인자들의 배열을 갈으킨다.
- `call()`은 배열로 넘긴 인자를 각각 하나의 인자로 넘긴다.

```
function myFunction() {
    console.dir(arguments);
    var agrs = Array.prototype.slice.apply(arguments);
    console.dir(args);
}
```

- args와 arguments의 `__proto__`의 값이 다르다

프로토타입 체이닝

- 자바스크립트에서 특정 객체의 프로퍼ㅣ나 메서드를 접근하려고 할때, 프로퍼티나 메서드가 없다면 `__proto__` 링크를 따라 자신의 부모 역활을 하는 프로토타입 객체의 프로퍼티를 차례대로 검색하는 것
- 리터럴 방식으로 만들어진 객체와, 생성자 함수로 생성된 객체가 표준 메서드에 접근 하는 방식이 약간은 다르다.
- 모든 프로토타입 체이닝의 종점은 Object.prototype이다.
- 이와 같은 방식으로 숫자, 문자열, 배열 등에서 사용되는 표준 메서드를 정의할 수 있다.
- 객체의 프로퍼티 읽기나 메서드를 실행할 때만 프로토타입 체이닝이 동작한다.(프로퍼티를 )



```
var s_prim = 'foo';
var s_obj = new String(s_prim);

console.log(typeof s_prim); // Logs "string"
console.log(typeof s_obj);  // Logs "object"

s_prim == s_obj
> true
s_prim === s_obj
> false
```

- 프로토타입 객체 역시 자바스크립트 객체이다.
- 프로토타입 객체 또한 메써드를 가질 수 있다.
- 디폴트 프로토타입은 다른 객체로 변경이 가능하다. 이를 이용해서 상속을 구현한다.
- 변경된 시점 이후에 생성된 객체들은 변경된 프로토타입 객체로 연결된다. 즉 `__proto__`의 값이 다르다.




## 궁금점


(문자열은 왜 기본타입인데 property를 호출 가능한것인가)
- 기본타입에 있는 메쏘드가 호출되거나 속성값을 보려고 할때 자바스크립트가 자동적으로 기본타입을 wrap 메쏘드를 호출하거나 속성값을 보도록 한다. (https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String#Distinction_between_string_primitives_and_String_objects
)
- 사용자가 정의한 표준 메서드 역시 동일하게 적용된다.
