
### 객체 

자바스크립트에서 객체는 간단하게 해쉬테이블이라고 생각하면된다. 모든 객체는 힙 메모리 공간에 저장됨.
프로퍼티에는 두가지 타입이 있으며, 데이터 프로퍼티와 접근자 프로퍼티가 있다.

##### 객체 프로퍼티

데이터 프로퍼티는 값에 대한 단 하나의 위치를 포함하여, 값을 읽고 씁니다. 이는 `Object.create()`와 `Object.defineProperties()`, `Object.defineProperty()` 함수를 사용할때 설정할 수 있습니다.
- `[[Configurable]]` 해당 프로퍼티가 delete를 통해 삭제하거나, 프로퍼티 속성을 바꾸거나 접근자 프로퍼티로 변환할수 잇음을 타나냅니다. 기본값 true
- `[[Enumerable]]` for-in 로프에서 해당 프로퍼티를 변환함을 나타냅니다. 기본값 tur
- `[[Writable]]` 프로퍼티의 값을 바꿀수 있음을 나타냅니다. 기본적으로 true
- `[[Value]]` 프로퍼티의 실제 데이터 값을 포합합니다. 이 속성의 기본값은 undefined

접근자 프로퍼티는 데이터 값이 들어 있지 않고 `getter`와 `setter`함수로 구성됩니다.
- `[[Configurable]]` 해당 프로퍼티가 delete를 통해 삭제하거나, 프로퍼티 속성을 바꾸거나 접근자 프로퍼티로 변환할수 잇음을 타나냅니다. 기본값 true
- `[[Enumerable]]` for-in 로프에서 해당 프로퍼티를 변환함을 나타냅니다. 기본값 tur
- `[[Set]]` 프로퍼티를 바꿀때 호출할 함수. 기본값 undefined
- `[[Get]]` 프로퍼티를 읽을때 호출할 함수. 기본값 undefined

- 접근자 프로퍼티

#### 객체를 생성하는 방법

1. 팩터리 패턴

```
function createPerson(name, age jon) {
  var o = new Object();
  o.name = name;
  o.age = age;
  o.job = job;
  o.sayName = function() {
    alert(this.name);
  };
  return o;
}

var person1 = createPerson("nicholas", 29, "Software Engineer");
var person2 = createPerson("nicholas", 29, "Software Engineer");
person1.sayName == person2.sayName
> false
```

생성된 객체가 어떤 타입인지 알 수 없음. 리터럴 방식이랑 크게 차이없음

2. 생성자 패턴

```
function Person(name, age jon) {
  this.name = name;
  this.age = age;
  this.job = job;
  this.sayName = function() {
    alert(this.name);
  };
}

```
class Super {
  static int a = 10;
}

class Sub extends Super {
  constructor() {
    console.(a);
  }
}
```

var person1 = new Person("nicholas", 29, "Software Engineer");
```
- 명시적으로 객체를 생성하지 않음
- 프로퍼티와 메서드는 this객체에 집적적으로 할당
- no return statement
- 함수를 new로 호출될때와 그냥 실행될때 내부적으로 실행되는 연산이 다르다. 
- 인스턴스마다 새로운 메서드가 생성되서 메모리 낭비가 심하다. 만약 메서드끼리 비교연산을 하면 다르다고 나옴.
instanceof 연산은 아래와 같이 실행된다.

```
function instanceOf(object, constructor) {
    while (object != null) {
        if (object == constructor.prototype) { //object is instanceof constructor
            return true;
        } 
        object = object.__proto__; //traverse the prototype chain
    }
    return false; //object is not instanceof constructor
}
```

3. 프로토타입 패턴
```
function Person() {

}

Person.prototype.name = "Nicholas"
Person.prototype.age = 29;
Person.prototype.job = "Software Engineer";
Person.prototype.sayName = function() {
  alert(this.name);
}

var person1 = new Person();
```

- `isPrototypeOf()`를 사용해서 객체 사이에 프로토타입 연결이 존재하는지 알 수 있다.
- `getPrototypeOf()`를 사용하면 객채에 `[[Prototype]]`의 값을 반환한다.
- 객체 인스턴스에서 프로토타입에 있는 값을 읽을 수는 있지만 삭제할수는 없다
- 객체 인스턴스에서 프로토타입에 있는 프로퍼티와 같은 이름의 프로퍼티를 만들게 되면, 해당 프로퍼티는 같은 이름의 프로퍼티를 가립니다. 하지만 delete연산을 사용하면 다시 접근할 수 잇다.
- `hasOwnProperty()`메서드를 사용해서 인스턴스에 존재하는 프로퍼티인지 확인 할 수 있습니다.

in 연산자
- `in` 연산자는 주어진 이름의 프로퍼티를 객체에서 접근할 수 있을때, 프로토타입이든 인스턴스에서 존재하든 모두 true를 반환합니다.
- `for in` 객체에서 접근할 수 잇고 나열 가능한 프로포티를 모두 반환하는데, 개발자가 만든 프로로퍼티는 `[[Enumerable]]`이 `false`라고 해도 반환됩니다.

- 프로토타입의 값을 찾느 작업은 런타임에 실행되므로, 프로포타입이 바뀌면 그 내용이 즉시 인스턴스에 반영되고, 심지어 프로토타입이 바뀌기 전에 생성된 인스턴스도 바뀐 내용을 반영합니다
- 하지만 프로토타입을 가르키는 객체를 대체하면 아에 연결이 끊어지게 됩니다.
- 프로토타입 패턴을 사용할때 문제점은 프로퍼티가 참조값을 포함할 경우, 생성된 객체 인스턴스가 모두 같은 객체를 가르키기 때문에 문제

4. 생성자 패턴과 프로토타입 패턴의 조화

```
function Person(name, age jon) {
  this.name = name;
  this.age = age;
  this.job = job;
}

Person.prototype = {
  constructor: Person,
  sayName : function() {
    return this.name;
  }
}


var person1 = new Person("nicholas", 29, "Software Engineer");
```

5. 동적 프로토타입 패턴
```
function Person(name, age jon) {
  this.name = name;
  this.age = age;
  this.job = job;

  if(typeof this.sayName != "function") {
    Person.prototype.sayName = function() {
      return this.name
    }
  }
}

var person1 = new Person("nicholas", 29, "Software Engineer");
```

- 이 패턴을 사용할 경우 객체가 어느 타입에서 만들어졌는지 확인 할 수 있습니다.

6. 기생 생성자 패턴

7. 방탄 생성자 패턴


생성자 훔치기 

상속 문제를 해결하기 위해서 사용된 테크닉이다. 부모의 생성자를 실행
```
function SuperType() {
  this.colors = ['red', 'blue', 'green'];
}

function SubType(){
  SuperType.call(this);
}
```

부모의 생성자를 실행하면서 매개변수를 넘기고 싶을때는 다음고 같이 진행한다.

```
function SuperType() {
  this.colors = ['red', 'blue', 'green'];
}

function SubType(){
  SuperType.call(this, 'Nicholas');
}
```

### 상속

ECMAScript에서는 구현 상속만 지원하며 구현 상속은 대개 프로토타입 체인을 통해 이루어집니다. 자바스크립트에서 상속은 프로토타입 체인을 형성해주는 과정이라고 할 수 있습니다. 

##### 프로토타입 체인

```
function SuperType() {
  this.property = true;
}

SuperType.prototype.getSuperValue = function() {
  return this.property;
}

function SubType() {
  this.subproperty = false;
}

SubType.prototype = new SuperType();
SubType.prototype.getSubValue = function() {
  return this.subproperty;
}

var instance = new SubType();
alert(instance.getSuperValue());
```
문제점 

- 이 패턴은 부모의 생성자를 호출할 수 없습니다.
- 프로토타입 프로터피에 들어있는 참조 값이 모든 인스턴스에서 공유될때 문제가 일어날 수 있습니다. 아래와 같은 코드에서 문제점이 발생할 수 있습니다

```
function SuperType() {
  this.colors = ['red', 'blue', 'green'];
}

function SubType() {

}

SubType.prototype = new SuperType();

var instance1 = new SubType();
instance1.colors.push('black');
console.log(instance1.colors);
>'red,blue,green,black';

var instance2 = new SubType();
console.log(instance2.colors);
>'red,blue,green,black';
```

SuperType의 인스턴스는 모두 colors 프로퍼티를 가지며 이 프로퍼티에는 인스턴스에 따라 고유한 배열이 포함됩니다. Subtype이 프로토타입 체인을 통해 SuperType을 상속하면 SubType.prototype은 SuperType의 인스턴스가 되므로 고유한 colors 프로퍼티를 갖는데, 이는 SubType.prototype.colors를 명시적으로 생성한거나 마찬가지입니다. 결국 SubType의 모든 인스턴스에서 colors 프로퍼티를 공유하게 됩니다.

> SuperType의 인스턴스는 모두 colors 프로퍼티를 가지는데, 이는 각각의 객체 인스턴스의 고유한 배열입니다. 하지만 이 객체를 SubType의 프로토타입 객체로 할당할 경우, 이는 명시적으로 SubType.prototype.colors를 선언한 것과 같은 의미입니다. 즉 SubType의 객체들은 모두 colors 배열을 공유하게 됩니다

또한 이는 상위 타입 생성자에 매개변수를 전달할 수 없습니다.

#### 생성자 훔치기

```
function SuperType() {
  this.colors = ["red", "blue", "green"];
}

function SubType() {
  SuperType.call(this);
}

var instance1 = new SubType();
instance1.colors.push('black');

console.log(instance1.colors);

> 'red,blue,green,black';

var instance2 = new SubType();
conole.log(instance2.colors);

>'red,blue,green';
```

생성자 훔치기 테크닉입니다. 하위 타입 생성자안에서 상위타입 생성자를 call이나 apply메소드를 사용해서 호출하면 모든 인스턴스가 자신만의 colors 프로퍼티를 갖게 되고 매개변수를 전달할 수 있게됩니다. 하지만 상위 타입의 프로토타입에 정의된 메서드는 하위 타입에서 접근할 수 없는 문제가 있습니다.

#### 조합 상속
위 두개의 조합해 두 패턴의 장점만을 취하려는 접근법 입니다.

```
function SuperType(name) {
  this.name = name;
  this.colors = ['red', 'blue', 'green'];
};

SuperType.prototype.sayName = function() {
  console.log(this.name);
}

function SubType(name, age) {
  SuperType.call(this, name);
  this.age = age;
}

SubType.prototype = new SuperType();

SubType.prototype.sayAge = function() {
  console.log(this.age);
}

var instance1 = new SubType('nicholas', 29);
instance1.colors.push('black');
console.log(colors);
> 'red,blue,green,black'
instance1.sayName();
> 'nicholas'
instance1.sayAge();
> 29

var instance2 = new SubType('greg', 27);
console.log(instance2.colors);
> 'red,blue,green';
instance2.sayName();
instance2.sayAge();

```

프로토타입 체인과 생성자 훔치기 패턴의 단점을 모두 해결한 조합 상속은 자바스크립트에서 가장 자주 쓰이는 상속 패턴입니다. 조합 상속은 instanceof()와 isPrototypeOf()에서도 올바른 결과를 반환합니다.

#### 프로토타입 생성

```
function object(o) {
  function F() {}
  F.prototype = o;
  return new F();
}
```

일단 다른 객체의 기반이 될 객체를 만들고, 기반 객체를 object()에 넘긴 다음 결과 객체를 적절히 수정해야 합니다. 이 방법은 Object.create() 메서드로 ES5에서 구현되었습니다.

#### 기생 상속

일단 삭속을 담당할 함수를 만들고, 어떤 식으로든 객체를 확장해서 반환한다는 것입니다. 
```


function createAnoter(original) {
  var clone = object(original);
  clone.sayHi = function() {
    console.log('hi');
  }
  return clone;
}

var person = {
  name: "Nicholas",
  friends: ["Shelby", "Court", "Van"]
};

var anotherPerson = createAnother(person);
anotherPerson.sayHi();
```

기생 상속을 이용해 객체에 함수를 추가하면 생성자 패턴과 비슷한, 함수 재사용과 관련된 비효율 문제가 생긴다.

### 기생 조합 상속

```
function object(o) {
  function F() {}
  F.prototype = o;
  return new F();
}

function SuperType(name) {
  this.name = name;
  this.colors = ["red", "blue", "green"];
}

SuperType.prototype.sayName = function () {
  return this.name;
}

function SubType(name, age) [
  SuperType.call(this, name);
}

inheritPrototype(SubType, SuperType) {
  var prototype = object(superType.prototype); // ES5 이상부터는 Object.create()라는 함수를 사용할 수 있다.
  prototype.constructor = subType;
  subType.prototype = prototype;
}

inheritPrototype(SubType, SuperType);
SubType.prototype.constructor = SubType;
SubType.prototype.sayAge = function() {
  return this.anem;
}
```

new 연산자를 간단하게 작성하면 다음과 같다

```
fucntion customNew(func, ...args) {
  var obj, ret, proto;
  // func.prototype이 객체인지 아닌지 확인함. 객체가 아닐경우 Object.prototype 리턴
  proto = Object(func.prototype) === func.prototype ? func.prototype: Object.prototype;
  // 새로운 객체 생성 with proto;
  obj = Object.create(proto);
  // func을 실행하면서 함께 넘어온 인자를 실행
  ret = func.apply(obj, Array.prototype.slice.call(args));
  if(Object(ret) === ret) {
    return ret;
  }
  return obj;
}
```
