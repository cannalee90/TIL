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
