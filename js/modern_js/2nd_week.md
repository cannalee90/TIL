# 문자열

## 2.4 템플릿 리터럴

템플릿 리터럴은 ES6에서 다음 문제에 대한 해결책이다.
1. Multiline string
2. Basic string formatting: 변수 값을 문자열 일부분으로 대체하는 능력
3. HTML escaping: HTML 안에 안전하게 삽입될 수 있도록 문자열을 변경하는 능력

### 2.4.2 멀티라인 문자열
```js
let message = `Multiline
string`;
console.log(message); // "Multiline
                      //  string"
console.log(message.lenght) // 16
```

```js
let message = `Multiline
               string`;
console.log(message); // "Multiline
                      //                    string"
console.log(message.lenght) // 31
```

두번째 라인의 모든 공백은 문자열 일부러 간주한다.

### 2.4.3 치환자 만들기

```js
let name = "Nicholas";
console.log(`hello ${name}`);
```

치환자 안의 내용은 자브스크립트 표현식이기 때문에, 다양한 것을 치환할 수 있다.

```
let name = "Nicholas",
    message = `Hello, ${`my name is ${name}`}`;

console.log(message) // "Hello, my name is Nicholas"
```

태그는 처리된 템플릿 리터럴 데이터와 함께 호출되는 간단한 함수다. 첫 번째 인자는 자바스크립트가 리터럴을 해석하여 얻은 리터럴 문자열로 이루터진 배열이다. 보통 태그 함수는 나머지 연자를 사용하여 정의한다

```js
let count = 10;
let price = 0.25;
let message = passthru`${count} items cost $${(count * price).toFixed(2)}.`

function passthru(liters, ...sub) {
  console.log(liters); //["", " items cost $", ".", raw: Array(3)]
  console.log(sub); //[10, "2.50"]
}
```

```js
let msg1 = `Multiline\nstring`;
let msg2 = String.raw`Multiline\nstring`;
console.log(msg1); // "Multiline
                   //  string"
console.log(msg2); // "Multiline\nstring"
```

`raw` 태그를 사용할 경우 원본 형태로 반환된다. 이처럼 원본 문자열 정보를 가져오는 기능은 필요한 경우 더 복잡한 처리를 가능하게 한다.

```js
function raw(literals, ...subs) {
  let result = "";
  for (let i = 0; i < subs.length; i++) {
    result += literals.raw[i];
    result += subs[i];
  }
  result += literals.raw[literals.length - 1];
  return result;
}
let message = raw`Multiline\nstring`;
console.log(message);
console.log(message.length);
```

위의 함수는 템플릿 태그를 사용해서 `String.raw()`의 함수를 모방한 함수이다. `literals`와 `substitutions.length`를 사용해서 위와 같이 처리하면 `substitutions` 배열의 끝을 넘지 않도록 작동한다.

# 함수

## 3.1 함수의 매개변수 기본값
ES6부터 자바스크립트 함수에 매개변수가 제공되지 않을 때 기본값을 추가함으로써, 다양한 개수의 매개변수를 처리하도록 함수를 정의할 수 있게 되었다.

### 3.1.1 ES5
```js
function makeRequest(url, timeout, callback) {
  timeout = (typeof timeout !== "undefined") ? timeout : 2000;
  callback = (typeof callback !== "undefined") ? callback: function() {};
}
```

번거롭지만 위와 같은 방법으로 사용하였다.

### 3.1.2 ES6
```js
function makeRequest(url, timeout = 2000, callback = function() {}) {

}
```
undefined가 넘겨질 경우 기본값을 사용하게 되지만, null값이 넘겨질 경우 기본값이 사용되지 않는다.

### 3.1.3 매개변수 기본값이 arguments 객체에 미치는 영향

```js
function mixArgs(first, second) {
  "user strict";
  console.log(first === arguments[0]); // true
  console.log(second === arguments[1]); // true
  first = "c";
  second = "d";
  console.log(first === arguments[0]); // false
  console.log(second === arguments[1]); // false
}

mixArgs("a", "b");
```
```js
function mixArgs(first, second = 'b') {
  console.log(first === arguments[0]); // true
  console.log(second === arguments[1]); // false
  first = "c";
  second = "d";
  console.log(first === arguments[0]); // false
  console.log(second === arguments[1]); // false
}

mixArgs("a");
```

ECAScript 6에서 매개변수 기본값을 사용하는 함수의 arguments 객체는 모드에 상관없이 ES5 strict 모드와 동일하게 동작하고, 매개변수 기본값의 존재는 arguments 객체를 매개변수로부터 분리한다.

### 3.1.4 매개변수 기본값 표현식

매개변수를 함수를 실행하여 반환된 값을 매개변수 기본값으로 사용할 수 있다. 만약 괄호를 빠뜨리고 사용하면 함수의 참조만 전달하게 된다. 앞에서 선언한 매개변수를 사용할 수 있다. 하지만 그 자신을 기본값으로 사용하거나 오른쪽에 있는 값을 먼저 사용할 경우 오류가 난ㅂ니다.

### 3.1.5 TDZ에서의 매개변수 기본값

```js
function add(first = second, second) {
  return first + second;
}

console(add(1, 1)); // 2
console.log(add(undefined, 1)); // ReferenceError
```

함수 매개변수는 함수 본문 스코프로부터 별도로 분리된 자체적인 스코프와 TDZ를 가지게 됩니다. 이를 [intermediate scope](http://dmitrysoshnikov.com/ecmascript/es6-notes-default-values-of-parameters/#conditional-intermediate-scope-for-parameters)라고 합니다.

### 3.2.1 ES5에서 이름을 명시하지 않은 매개변수
```js
function pick(object) {
  let result = Object.create(null);
  for(let i = 1, len = arguments.length; i < len; i++) {
    result[arguments[i]] = object[arguments[i]];
  }
  return result;
}

let book = {
  title: "Understanding ECMAScript 6",
  author: "Nicholas C. Zakas",
  year: 2016
};

let bookData = pick(book, "author", "year");
console.log(bookData.author);
console.log(bookData.year);
```

1. 이 함수는 매개변수 하나 이상을 처리할 수 있다는 것이 명확하지 않다.
2. 첫 번째 매개변수는 명시하여 바로 사용하기 때문에, 복사하기 위한 프로퍼티를 찾을 때 arguments 객체 탐색을 0 대신 1에서 시작해야만 한다.

### 3.2.2 나머지 매개변수

나머지 매개변수는 `...`이라고 나타낸다. 함수에 전달된 매개변수의 나머지를 포함한 배열이 된다.

1. 나머지 매개변수는 반드시 하나여야 하고, 마지막 위치에서만 사용할 숭 잇다.
2. 객체 리터럴 setter에서는 나머지 매개변수를 사용할 수 없다.

arugments 객체는 나머지 매개변수와 관게없이 함수에 전달된 매개변수를 항상 정확하게 반영한다.

## 3.4 전개 연산자

전개 연산자는 배열을 나누어 함수에 개별적인 인자로 나타낸다.

```js
let values = [1,2,3,4,5];
console.log(Math.max(...values)); // 5
console.log(Math.max(...values, 10)) // 10
```


## 3.5 name 프로퍼티

익명 함수 표현식이 일반화되면서 디버깅이 까다로워졌고, 많은 경우 stack trace를 읽고 해석하기가 어려워졌다.

```js
function doSomething() {}

var doAnotherThing = function() {}

console.log(doSomething.name); // "doSomething"
console.log(doAnotherThing.name); // "doAnotherThing"
```

### 3.5.2 특별한 name 프로퍼티의 예

```js
var doSomething = function doSomethigElse() {};
var person = {
  obj: {
    sayNName: function() {

    }
  }
  get firstName() {

  },
  sayName: function() {

  }
}
console.log(doSomething.name); // "doSomethigElse"
console.log(person.sayName.name); // "sayName"
var descriptor = Object.getOwnPropertyDescriptor(person, "firstName");
console.log(descriptor.get.name); // "get firstName"
console.log()
console.log((new Function()).name); // "anonymous"
console.log(person.obj.sayNName.name) // "sayNName"
```

1. domSomething.name은 함수 표현식에 "doSomethingElse"라는 이름이 우선순위가 높다. 
2. getter 함수의 이름은 일반적인 메서드와 차이를 나타내는 "get firstName"이다.
3. setter 함수의 이름은 일반적인 메서드와 차이를 나타내는 "set firstName"이다.
4. 익명 함수의 이름은 "anonymous"이다.
5. 중첩된 오브젝트안에 있는 함수 이름도 같다.

## 3.6 함수의 두 가지 용도를 명확히 하기

ES5까지의 함수는 new 없이 호출괴거나 new와 함께 호출되는 두가지 용도로 사용되고 있었다. 이는 혼란을 일으킬 수 있기 때문에, ES6에서는 몇 가지 개선이 이루어졌다.

- 함수를 new 없이 호출할 때는 함수를 실행하는 `[[Call]]` 메서드가 실행
- 함수를 new로 호출할 때 `[[Constructor]]` 메서드를 실행(생성자

### 3.6.1 ES5에서 함수 호출을 결정하는 요인

ES5에서 함수를 new와 호출했는지 판단하는 가장 일반적인 방법은 instanceof를 사용하는 것이다. 하지만 `call`이나 `apply`를 사용할 경우에는 정상적으로 작동하지 않는다.

```js
function Person(name) {
  if(this instanceof Person) {
    this.name = name;
  } else {
    throw new Error("You must use new with Person");
  }

  var person = new Person("Nicholas");
  var notAPerson = Person.call(person, "Michael");
}
```

이 예제에서는 person객체가 this에 바인딩되기 때문에 생성자로써 호출되었는지 정확히 판단할 수 없다.

### 3.6.2 new.target 메타 프로퍼티

ES6에서는 문제를 해결하기 위해 new.target 메타 프로퍼티가 도입되었다. 메타 프로퍼티 `new.target`에는 `[[Constructor]]`가 실행될 경우 new 연산자의 실행 대상이 할당된다. `[[Call]]`이 실행되면 `new.target`은 `undefined`이다.

```js
function Person(name) {
  if(typeof new.target !== "undefined") {
    this.name = name;
  } else {
    throw new Error("You muse use with Person.!");
  }
}

var person = new Person("Nicholas");
var notAPerson = Person.call(person, "Michael"); //Uncaught Error: You muse use with Person.!
```

```js
function Person(name) {
  if(new.target === Person) { //new.target undefined
    this.name = name;
  } else {
    throw new Error("You muse use with Person.!");    
  }
}

function AnotherPerson(name) {
  Person.call(this, name);
}

var Person = new Person("Nicholas");
var anotherPerson = new AnotherPerson("Nicholas"); //에러 발생
```
`new.target`을 추가하여서 함수 호출과 관련된 모호한 부분을 명확히 한다.

## 3.7 블록 레벨 함수

ES5 strict 모드는 블록 내부에서 함수 선언을 할 때마다 에러를 발생시킨다. ES6에서는 블록 내부에서 함수 선언이 가능하고 최상단으로 호이스팅된다.

```js
'use strict'
if(true) {
  console.log(typeof doSomething); // "function"

  function doSomething() {

  }

  doSomething();
}

console.log(doSomething) // "undefined"
```

### 3.7.1 블록 레벨 함수의 사용 시기

블록 레벨 함수는 let 함수 표현식과 유사하지만, 정의된 블록의 최상단으로 호이스팅 된다는 것이다. let 함수 표현식의 경우는 TDZ가 적용된다.

### 3.7.2 Non-strict 모드의 블록 레벨 함수

ES6에서의 non-strict 모드에서도 블록 레벨 함수를 허용하지만 동작이 약간 다르다.

```js
if(true) {
  console.log(typeof doSomething); // "function"
  function doSomething() {

  }
  let doSomethingElse = function() {

  }
  doSomething();
}

console.log(typeof doSomething); // "function"
console.log(typeof doSomethingElse) // undefined
```

non-strict 모드에서는 전역 스코프로 호이스팅 되어 if 블록의 바깥 부분에도 존재한다. 하지만 let 함수 표현식은 호이스팅 되지 않는다.

### 3.8 화살표 함수

화살표 함수는 화살표를 사용하는 새로운 문법으로 정의한다.

- `this`, `super`, `arugment`, `new.target`의 값은 그 화살표 함수를 가장 근접하게 둘러 싸고 있는 일반함수에 의해 정의된다.
- `[[Constrcut]]` 메서드가 없으므로 생성자 함수로 사용할 수 없다.
- 프로토타입이 없다.
- 함수 내부에서 `this`를 변경할 수 없다.
- `arguments`가 바인딩 되지 않기 때문에, 명시한 매개변수와 나머지 매개변수에 의존해야 한다.
- 매개변수를 중복하여 사용할 수 없다.
- `name` 프로퍼티를 가진다.

3.8.1 화살표 함수 문법

```js
var reflect = value => value;

// 사실상 같은 코드

var reflect = function(value) {
  return value;
}
```

```js
let sum = (num1, num2) => num1 + num2;

// 사실상 같은 코드

let sum = function(num1, num2) {
  return num1 + num2;
}
```

```js
let getName = () => "Nicholas";

// 사실상 같은 코드

let getName = function() {
  return "Nicholas";
}
```

```js
let sum = (num1, num2) => {
  return num1 + num2;
}

// 사실상 같은 코드

let sum = function(num1, num2) {
  return num1 + num2;
}
```

```js
let doNothing = () => {};

// 사실상 같은 코드

let doNothing = function() {};
```

바깥에 객체 리터럴을 반환하는 화살표 함수는 괄호로 객체 리터럴을 감싸야만 한다.

```js
let getTempItem = id => ({id: id, name: "Temp"});

// 사실상 같은 코드

let getTempItem = function(id) {
  return {
    id: id, 
    name: "Temp",
  }
}
```

### 3.8.2 즉시 실행 함수 표현식 만들기

```js
let person = function(name) {
  return {
    getName: function() {
      return name;
    }
  }
}("Nicholas");

console.log(person.getName());

// 사실상 같은 코드

let person = ((name) => {
  return {
    getName: function() {
      return name;
    }
  }
})("Nicholas");

console.log(person.getName());
```
