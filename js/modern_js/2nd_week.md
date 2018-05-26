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

