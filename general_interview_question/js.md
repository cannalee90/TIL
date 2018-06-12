### Primitive type

Javascript에서는 크게 primitive type과 reference type이 있습니다.

JS에서 primitive type은 `Number`, `String`, `Boolean`, `null`, `undefined`, `symbol`이 있습니다. 그리고 아래와 같은 특징을 가지게 됩니다.

- 각각의 값은 모두 스택에 저장됩니다.
- 변수 그 자체가 하나의 값을 나타냅니다.
- 인자가 전달될때 call by value의 형태로 넘어갑니다.

```
Number.prototype.whoAmI = function() { console.log(typeof this);}

var num = 10;

typeof num; // "number"

num.whoAmI(); // "object"
typeof num // "number"
```

- 위와 같은 코드에서 str은 객체가 아님에도 불구하고 암묵적으로 primitive 객체로 래핑되서 실행됩니다. 
- primitive type의 값은 immutable합니다.

references

http://meetup.toast.com/posts/143
inside javascript
web developer for javascript

### Java와 JS 차이점

Java
1. compile 언어
2. class based OOP
3. 정적 타입 언어. 작성하는 시점에 변수가 어떤 타입인지 정해진다. 따라서 좀 더 퍼포먼스가 좋고 디버깅이 쉽다. 
4. 웹에서는 주로 서버사이드 언어로 사용된다.
5. 여러개의 쓰레드를 생성해서 동시에 여러 작업을 수행할 수 있다.

JS
1. 인터프리트 스크립트 언어이다.(요즘엔 엔진에 따라서 컴파일 하기도 한다)
2. 동적 타입 언어이다. 실행시킬때까지 변수가 어떤 타입인지 정해지지 않는다. 이를 극복하기 위해서 typescript나 flow같은 도구들이 있다.
3. 일반적으로 브라우저위에서 실행된다.(요즘엔 RN이나 ionic 같은 경우도 있다)
4. 프론트사이드 언어로 주로 사용한다.
5. JS에서는 메인쓰레드가 하나이다. 따라서 event-loop라고 불리는 큐시스템을 이용해서 동시성 문제를 해결한다.

references

https://www.codecademy.com/en/forum_questions/4fe46886d5de070003017288
https://www.quora.com/What-is-the-difference-between-Java-and-JavaScript

### Hosting

ES6이전까지 자바스크립트는 스코프 단위가 block 단위가 아니라 함수 단위였습니다. 이때, `var`로 선언된 변수들은 모두 함수의 최상위 혹은 전역 컨텍스트의 최상위에서 `선언`됩니다. 하지만 변수의 특정값이 `할당` 되어지지 않기 때문에 변수의 값은 `undefined`가 출력됩니다.

```js
console.log(x); // undefined
var x = 10;
console.log(10); // 10
```

함수의 경우도 마찬가지로 함수 선언식으로 나타낸 함수들은 함수의 최상위 혹은 전역 컨텍스트의 최상위에로 끌어올려지게 됩니다. 함수 선언식으로 나타낸 함수들은 정상적으로 실행됩니다.

```
(function a() {
	f();
	function f() {
		console.log('hello f');	
    }
})(); // hello f
```

함수 표현식으로 나타낸 함수들을 선언된 곳보다 먼저 호출하게 되면 `Syntax Error`가 발생하며 제대로 실행되지 않습니다.

references

https://github.com/JaeYeopHan/Interview_Question_for_Beginner/tree/master/JavaScript

### Closure

간단하게 말하면 이미 생명주기가 끝난 외부(부모) 함수의 변수를 참조하는 것을 클로저라고 말한다. 조금 더 풀어서 말하면, 생성될때 당시의 환경을 기억하는 함수를 말한다. 
```
var color = 'red';
function foo() {
    var color = 'blue'; // 2
    function bar() {
        console.log(color); // 1
    }
    return bar;
}
var baz = foo(); // 3
baz(); // 4
```

`bar`의 경우 자신이 생성된 렉시컬 스코프를 벗어나 global에서 호출이 되었다. 하지만 스코프 탐색은 현재 실행 스택과 관련없는 `foo()`를 거쳐갔다. 이와 같은 `bar, baz`와 같은 함수를 클로저라고 한다. 추가적으로 `foo()`의 렉시컬 인스턴스가, GC에 의해서 회수되어야 하지만, `bar()`에 의해서 참조되기 때문에 회수되지 않는다. 따라서 클로저를 남용하게 되면 메모리 이슈가 생기게 된다.

클로저는 다음과 같이 활용할 수 있다.

```js
function counter() {
    var _count = 0;

    return function() {
        _count += 1;

      return _count;
    };
}
var counterFirst = counter();
console.log(counterFirst()) // 1
console.log(counterFirst()) // 2
```

위와 같이 구현할 경우, `_counter`라는 변수는 외부에서 접근할 수 있는 방법이 전혀 없다. 즉 `counter`함수 내에서만 접근할 수 있게 되는 private 변수가 만들어졌다.

references

http://meetup.toast.com/posts/86
http://meetup.toast.com/posts/90
inside javascript

### CDN

content delivery network라고 해서 분산화된 네트워크를 칭합니다. 보통 글로벌 서비스를 운영할때 edge서버에 서버의 static한 데이터들을 복사해놓습니다. 그리고 클라이언트에서 특정 리소스를 요청할 경우 만약 edge서버에서 그 데이가 있을때, 물리적으로 가장 가까운 edge 서버에서 요청을 처리하는 식으로 사용됩니다. 대표적으로 cloudflare나 cloudfront와 같은 서비스가 대표적입니다. 


https://docs.microsoft.com/ko-kr/azure/cdn/cdn-overview

### 프론트엔드 성능을 향상시키기 위한 방법
1. static 파일을 CDN을 사용해서 캐슁해서 사용한다.
2. 사용하지 않는 코드들과 파일은 bundle 파일에 포함시키지 않는다.
3. minify css, minify javascript
4. medium과 같이 이미지를 한번에 로딩하는 것이 아니라 lazy-loading을 사용한다
5. React의 경우 `sholudComponentUpdate`와 같은 라이프사이클 메서드를 잘 사용해서 ui에 불필요한 업데이트를 조정한다.
6. 폰트의 경우에도 sub-set을 사용해서 초기 로딩속도를 줄인다.

https://css-tricks.com/case-study-boosting-front-end-performance/
https://hackernoon.com/optimising-the-front-end-for-the-browser-f2f51a29c572?gi=6aa37967a75a


### call, apply, bind

call과 apply는 명시적으로 this를 바인딩하기 위해서 사용하는 메서드 입니다. 두개의 차이는 매개변수를 넘겨주는 방식이 차이가 있습니다. apply의 경우 다음과 같이 사용됩니다. `.apply(this, [...])`와 같이 매개변수를 배열의 형태로 넘겨줍니다. call의 경우는 `.call(this, params1, params2, params3)`과 같이 각각을 콤마로 나눠서 넘겨주는 형태로 넘겨줍니다. 

아래와 같이 노드리스트와 같이 유사배열의 객체에서 배열의 메서드를 사용하기 위해서 사용합니다.

```js
nodelist = document.querySelector('li');
Array.prototype.foreach.call(nodelist, (node) => {
  console.dir(node);
)}
```

`bind()`의 경우 함수는 호출하지 않지만, this가 바인딩된 함수가 만들어진다.

### let, const, blockscope

ES5까지는 블록스코프를 지원하지 않았지만, ES6에서 새롭게 나온 키워드인 let과 const의 경우에는 block scope를 지원합니다. let과 const는 블록레벨 스코프를 지원합니다. 또한 hoist가 되지 않기 때문에 

### 자바스크립트의 장단점

1. 인터프리터 언어기 때문에 배우기 쉽고 생산성이 높다.
2. 기본적으로 브라우저위에서 돌아가는걸 생각하고 작성된다.
3. 정적언어가 아니기 때문에 기본적으로 속도가 느리다.

### Arrow function

- `this`, `super`, `arugment`, `new.target`의 값은 그 화살표 함수를 가장 근접하게 둘러 싸고 있는 일반함수에 의해 정의된다.
- `[[Constrcut]]` 메서드가 없으므로 생성자 함수로 사용할 수 없다.
- 프로토타입이 없다.
- 함수 내부에서 `this`를 변경할 수 없다.
- `arguments`가 바인딩 되지 않기 때문에, 명시한 매개변수와 나머지 매개변수에 의존해야 한다.
- 매개변수를 중복하여 사용할 수 없다.
- `name` 프로퍼티를 가진다.


### 웹 프론트엔드 개발자란 무엇이라고 생각하나?

좁은 의미에서 말하면 서비스를 구현할때, 자바스크립트, HTML, CSS를 사용해 시각적인 목업을 웹 브라우저에서 실제로 작동하게 만드는 일을 하는 사람들이다. 일반 사용자와 최전방에서 맞닿아 있는 부분을 구현해야하고 브라우저와 기기의 한계를 잘 파악해서 스펙이 잘 구현되어 질 수 있도록 해야한다.

http://ppss.kr/archives/26024


### localstorage sessionstorage cookie

HTML5에서 추가된 기능으로써 브라우저에서 사용할 수 있는 key-value 저장소입니다.
localSroage는 데이터가 영구적으로 저장되지만 session storage는 탭을 닫거나 윈도우를 닫을경우(페이지 세션이 만료될 경우) 데이터가 초기화 됩니다.
유저가 웹 사이트에 방문했을때 서버가 사용자에 컴퓨터에 기록하는 정보이다. 주로 클라이언트에 대한 정보를 저장, 4kb의 용량한계, 별도의 암호화 부재, HTTP요청때마다 전송됨, 만료일이 존재, 높은 호환성

### HTTP HTTPS

### 실행 컨텍스트

excution context란 실행 가능한 코드가 실행되기 위해 필요한 환경이라고 할 수 있으며 3가지 종류가 있습니다. 전역 코드, eval 코드, 함수 코드의 종류가 있으며, 각각의 환경에 따라 코드의 실행에 필요한 정보들이 있으며, 변수, 함수선언, scope, this와 같은 정보들을 자바스크립트 엔진에서 물리적 객체의 형태로 관리하게 됩니다.

코드를 실행하게 되면 논리적 스택 구조를 가진 새로운 스택이 생성되고, 전역코드가 맨 먼저 추가되고 함수를 호출하면 이전 실행 컨텍스트 위에 쌓이게 됩니다. 함수 실행이 끝나면 해당 함수의 실행 컨텍스트를 파기하게 됩니다.

실행 컨텍스트는 3가지의 객체를 가지게 됩니다.

1. Variable Object
2. Scope Chain
3. This


#### 전역 객체

전역 객체는 전역 컨텍스트일 경우 전역 객체를 가르키고, 함수 컨텍스트일 경우에는 매개변수와 인수들의 정보를 가지고 있는 활성 객체를 가르키게 됩니다. 

#### 스코프 체인

스코프 체인은 해당 전역 또는 함수가 참조할 수 있는 변수, 함수 선언 등의 정보를 담고 있는 전역 객체(GO) 또는 활성 객체(AO)의 리스트를 가리킨다. 함수 컨텍스트는 최종적으로 전역 객체를 가르키게 됩니다. 스코프체인은 코드내에서도 [[scope]] 프로퍼티로 참조할 수 있습니다.

#### this value

해당 컨텍스트 내에서 사용하는 this 값을 말합니다.

### 실행 컨텍스트의 생성 과정

코드를 실행하게 되면, 다음과 같은 순서로 실행되게 된다.

1. 전역 코드에 진입
2. 전역 실행 콘텍스트가 생성되고 실행 컨텍스트 스택에 쌓임
3. 실행 컨텍스트를 바탕으로 아래와 같은 처리가 실행
    - 스코프 체인의 생성과 초기화
    - Variable Instantiation(변수 객체화) 실행
    - this value 결정

### 변수 선언

변수 선언을 세분화 하면 다음과 같다.

- 선언 단계(Declaration phase) : 변수 객체(Variable Object)에 변수를 등록한다. 이 변수 객체는 스코프가 참조할 수 있는 대상이 된다.
- 초기화 단계(Initialization phase) : 변수 객체(Variable Object)에 등록된 변수를 메모리에 할당한다. 이 단계에서 변수는 undefined로 초기화된다.
- 할당 단계(Assignment phase) : undefined로 초기화된 변수에 실제값을 할당한다.

### event loop

스펙에 명시되어 있지는 않지만, 단일 쓰레드기반의 자바스크립트가 I/O나 http 요청 같은 비동기 작업에서 동시성을 지원하기 위한 장치. call stack이 비어있을때 Microtasks queue와 Tasks queue를 감시하면서 다음에 실행되어야할 코드를 call stack에 넣어주는 역활을 합니다. microtasks는 `Promise`와 `mutationObserver`이 있으며 항상 task보다 먼저 실행되게 됩니다. 또한 task와 task에는 브라우저 렌더링이 일어날수도 있습니다. task는 각종 비동기 함수, Web API영역에 있는 함수들을 말하고 작업이 순차적으로 수행되는 것을 보장합니다. `setTimeout`


http://sculove.github.io/blog/2018/01/18/javascriptflow/
http://meetup.toast.com/posts/89


### call stack

브라우저나 자바스크립트 엔진에서 함수의 계층적 실행순서를 보장해주는 정보를 저장하는 자료구조입니다. 보통 쓰레드마다 한개의 스택이 할당되며, 자바스크립트의 경우 한개의 call stack을 가지고 콜 스택내에서는 실행 순서가 보장됩니다. 보통 함수가 실행될때 call stack에 들어가게 되고, 함수 수행이 끝나면 call stack에서 파괴됩니다.

- 어디서 어떤 함수가 실행되었는지
- 현재 어떤 함수가 실행중인지
- 현재 함수가 끝나면 어디로 돌아가야하는지에 대한 정보를 저장하고 있습니다. 


### 자바스크립트에서 함수의 특징

- 함수는 1급 객체로써, 런타임에 실행될 수 있으며, 변수에 할당할 수 있고, 다른 변수에 참조를 복사할 수 있으며, 확장이 가능하고, 몇몇 특별한 경우를 제외하면 삭제할 수 있다.
- 다른 함수의 인자로 전달할 수 있고, 다른 함수의 반환 값이 될 수 있다.
- 또한 자바스크립트내에서는 새로운 객체를 만들때 실행됩니다.

- ES5에서는 블록스코프를 지원하지 않기 때문에, scope의 단위로도 쓰였다. `var`로 변수를 선언할 경우 함수를 기준으로 호이스팅이 일어나게 됩니다.

### 이벤트 버블링

- 특정 이벤트가 발생했을때 해당 이벤트가 더 상위의 화면 요소들로 전달되는 특성을 말한다.
- `event.stopPropagation()`를 통해서 전달을 막을 수 있습니다.
- 하위 요소에 각각 이벤트를 붙이지 않고 상위 요소에서 하위 요소의 이벤트들을 제어하는 방식을 이벤트 위임이라고 한다. 


### Promise
> A promise is an object that may produce a single value some time in the future

자바스크립트 비동기 처리에 사용되는 객체로써 3가지의 상태를 가집니다.
- `Pending` : (대기) 함수를 처음 실행하거나, 비동기 로직이 처리중이거나 `resolve()` 함수를 실행하지 않은 상태
- `Fulfilled` : (함수) 콜백 함수 인자 `resolve()`를 실행한 상태
- `Rejected` : 실패



