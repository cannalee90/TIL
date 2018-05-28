# Temporal Dead Zone와 Default Scope

다음은 일요일 모던자바스크립트 스터디에서 나온 내용을 추가적으로 공부한 내용입니다.

아래 레퍼런스의 글들을 요약 발췌 번역한 글입니다.

ES6로 넘어오면서 ES5에서 없는 블록스코프가 지원되기 시작했습니다. 개발자들은 `var`대신 `let`과 `const`를 사용할수 있게 되었습니다. `var` 키워드를 사용해서 변수를 선언할 경우와는 다르게 `let`과 `const`는 변수가 선언되기 이전에 그 변수를 사용(read/write)할 경우 reference error를 발생시킵니다. 또한 전역에서 `let`과 `const`를 사용해서 변수를 선언할 경우 window 객체에 속성으로 사용할 수 없습니다. 또한 변수가 선언되기 이전에 그 변수를 사용할 수 없는 구역을 `TDZ`라고 합니다.

## TDZ

간단한 TDZ는 아래와 같습니다.

```js
console.log(x)
const x = 'hey';
```

위에서 소개한대로 `const`와 `let`으로 선언된 변수를 선언문 전에 사용하면 reference error를 발생시킵니다. 그냥 단순하게 넘길수도 있지만 조금 더 생각해 봅시다.

```js
let x = 'outer scope';
(function() {
    console.log(x);
    let x = 'inner scope';
}());
```

위와 같은 코드는 조금 더 생각해볼 여지가 있습니다. 단순히 생각해보면 `outer scope`를 참조한다고 생각할 수 있지만, 코드를 실행해보면 reference error를 발생시킵니다. 

다음은 ECMA 스펙에 서술되어 있는 내용입니다.

> **13.2.1** Let and Const Declarations
NOTE let and const declarations define variables that are scoped to the running execution context’s LexicalEnvironment. **The variables are created when their containing Lexical Environment is instantiated but may not be accessed in any way until the variable’s LexicalBinding is evaluated.** A variable defined by a LexicalBinding with an Initializer is assigned the value of its Initializer’s AssignmentExpression when the LexicalBinding is evaluated, not when the variable is created. If a LexicalBinding in a let declaration does not have an Initializer the variable is assigned the value undefined when the LexicalBinding is evaluated.

스펙에서는 TDZ라는 것이 명시되지 않았지만, 두껍게 표시된 문장이 TDZ를 설명합니다.

```js
let a = f();
const b = 2;
function f() { return b; }
```

위와 같이 부모 스코프를 참조하는 경우에도 refrence error를 발생시킵니다.

### TDZ for Conditional Default Parameter

```js
a = 1;
(function(a = a) {}()); // Reference Error
```

초기화 전에 자기 자신을 참조할 경우 에러가 납니다.

```js
function foo(x, y = x) { // OK
  ...
}
```

es6의 파라미터는 왼쪽부터 초기화되기 때문에, 위에 예제는 문제가 없습니다.

```js
// 문제 없음
(function(a, b = a) {
    a === 1;
    b === 1;
}(1, undefined));

// 디폴트 파라미터는 왼쪽부터 수행되기 때문에, B가 TDZ에 있으므로 A를 초기화 할때 에러가 난다.
(function(a = b, b) {
}(undefined, 1)); // ReferenceError

// a가 a를 초기화 시킬때 a는 TDZ에 속하기 때문에, 에러가 난다. 

(function(a = b, b) {
    console.log(a, b);
}(undefined, 2));
```

ES5와 다르게 매개변수가 기본값을 가지는 몇몇의 경우 ES6는 intermediate scope를 정의해서 저장하게 됩니다. 그리고 이 스코프는 함수 바디의 scope와 공유되지 않습니다. 아래의 코드를 확인해봅시다

```js
var x = 1;
 
function foo(x, y = function() { 
    console.log(x);
    x = 2; 
    console.log(x);        
  }) {
  y();
  var x = 3;
  console.log(x);
};
foo();
console.log(x);
```

위 코드에서의 출력 순서는 `undefined` `2` `3` `1`이다. 인자가 넘어가지 않았기 때문에, x는 `undefined`가 되고, 그 매개변수의 기본값은 intermediate scope에 저장됩니다. 이 스코프는 함수 바디의 스코프와 공유되지 않습니다. 위에 코드에서의 스코프를 분리해보면 아래와 같습니다.

```
{x: 3} // 함수
{x: undefined, y: function() { x = 2; }} // 매개변수
{x: 1} // 전역
```

## Params scope가 필요한 이유

ES5에서와 같이 함수 바디와 스코프를 공유하지 않는 이유는 아래와 같은 코드때문입니다.

```
var x = 1;
 
function foo(y = function() { return x; }) {
  var x = 2;
  return y();
}
 
foo();
```

ES5의 경우 x는 2를 리턴하게 됩니다. 하지만 우리가 쉽게 확인할 수 있듯이 x는 1을 리턴해야합니다. 

## intermediate scope가 만들어지지 않을때

```
var x = 1;
 
function foo(x, y) {
  if (typeof y == 'undefined') {
    y = function() { x = 2; };
  }
  var x = 3;
  y();
  console.log(x); // 2
}
 
foo();
console.log(x); // 1
```

하지만 기본값이 없으면 intermediate scope를 만들지 않습니다. 이렇게 복잡하게 설계한 이유는 ES5와의 호환을 위해서입니다. 위의 예제를 보면 수동으로 구현한 y에서는 x의 값을 공유하게 되는걸 확인 할 수 있습니다. 위의 모든 예제는 변수가 `var` 타입일때만 유효합니다.

## TDZ의 필요성

1. 프로그레밍 에러를 잡아내기 위해서.
2. `const`를 제대로 구현하는건 매우 어려운일이었기 때문에, 결국 TDZ가 최적의 솔루션으로 부상하게 되었다. 또한 `let` 역시 TDZ를 가짐으로써 `let`과`const` 사이의 전환이 이루어질때 문제가 생기지 않도록 수정했다. 
3. 자바스크립트가 차후에 이를 방어하는 메커니즘을 만들수도 있는데, 만약 이때 TDZ에 있는 변수가 undefined에러가 나면 문제가 생긴다.

## references

1. https://mail.mozilla.org/pipermail/es-discuss/2012-September/024996.html
2. http://2ality.com/2015/10/why-tdz.html
3. https://gist.github.com/rwaldron/f0807a758aa03bcdd58a
4. http://jsrocks.org/2015/01/temporal-dead-zone-tdz-demystified
5. http://dmitrysoshnikov.com/ecmascript/es6-notes-default-values-of-parameters/#conditional-intermediate-scope-for-parameters
