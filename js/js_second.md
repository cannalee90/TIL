#Code School JS

### loop

- while과 for는 c와 비슷한 방법으로 쓰인다.


### conditional

- 기본적으로 c와 비슷하다

### typeof

- 변수나 타입을 구분할 수 있다.

~~~
> typeof true
< object
> typeof 123
< number
> var obj = {type: "hello"}
< object

~~~

- typeof로 구분할 수 있는 것들은 다음과 같다
- 아래 소스를 참고하자

~~~

// Numbers
typeof 37 === 'number';
typeof 3.14 === 'number';
typeof Math.LN2 === 'number';
typeof Infinity === 'number';
typeof NaN === 'number'; // Despite being "Not-A-Number"
typeof Number(1) === 'number'; // but never use this form!


// Strings
typeof "" === 'string';
typeof "bla" === 'string';
typeof (typeof 1) === 'string'; // typeof always returns a string
typeof String("abc") === 'string'; // but never use this form!


// Booleans
typeof true === 'boolean';
typeof false === 'boolean';
typeof Boolean(true) === 'boolean'; // but never use this form!


// Symbols
typeof Symbol() === 'symbol'
typeof Symbol('foo') === 'symbol'
typeof Symbol.iterator === 'symbol'


// Undefined
typeof undefined === 'undefined';
typeof declaredButUndefinedVariable === 'undefined';
typeof undeclaredVariable === 'undefined';


// Objects
typeof {a:1} === 'object';

// use Array.isArray or Object.prototype.toString.call
// to differentiate regular objects from arrays
typeof [1, 2, 4] === 'object';

typeof new Date() === 'object';


// The following is confusing. Don't use!
typeof new Boolean(true) === 'object';
typeof new Number(1) === 'object';
typeof new String("abc") === 'object';


// Functions
typeof function(){} === 'function';
typeof class C {} === 'function';
typeof Math.sin === 'function';
~~~

- confirm의 리턴은 true / false 이다.
- alert()을 사용해서 경고창을 띄울 수 있다.
- prompt를 이용해서 인풋을 받을 수 있다.


### Array

- 자바스크립트에서는 array역시 object타입이다.
~~~
var arr = [1,2,3]
> typeof arr
< object
~~~
