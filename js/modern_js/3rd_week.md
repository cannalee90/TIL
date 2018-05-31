# 4장 확장된 객체 기능

## 4.1 객체 카테고리

ES6 명세에서는 표준 객체를 설명하기 위해 각 카테고리를 명확하게 정의한다.

- ordinary objects(일반객체): 자바스크립트 객체의 모든 기본 내부 동작을 가진다.
- exotic objects(이형 객체): 기본과 다른 내부 동작을 가진다
- standard objects(표준 객체): ES6에 정의되었으며, **Array**, **Date** 등이 있다. 표준 객체는 일반 객체이거나 이형 객체일 수 있다.
- built-in objects(내장 객체): 스크립트가 실행되는 자바스크립트 실행 환경에 존재한다. 모든 표준 객체는 내장 객체이다.

## 4.2 객체 리터럴의 문법 확장

ES6에서는 자바스크립트에서 가장 인기 잇는 개체 생성방식인 객체 리터럴을 좀 더 강력하고 간결하게 만들었다.

### 4.2.1 프로퍼티 초기자 축약

ES6에서는 프로퍼티 초기자 축약 문법(property initializer)을 이용하여 프로퍼티 이름과 지역 변수의 중복을 제거할 수 있다.

```js
// ES5
function createPerson(name, age) {
  return {
    name: name,
    age: age,
  }
}

// ES6
function createPerson(name, age) {
  return {
    name,
    age
  };
}
```

### 4.2.2 간결한 메서드(concise methods)

ES6에서는 객체 리터럴에서 메서드 할당을 위한 문법이 개선되었다. 

```js
var person = {
  name: "Nicholas",
  sayName: function() {
    console.log(this.name);
  }
}

var person = {
  name: "Nicholas",
  sayName() {
    console.log(this.name);
  }
}
```