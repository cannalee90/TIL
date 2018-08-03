js arrow function을 남발할 경우 퍼포먼스 이슈가 있다.

일단 간단하게 설명하자면 일반적으로 클래스를 통해 자바스크립트의 객체를 생성하게 될때, 클래스의 메서드는 prototype 객체에 저장되게 되고, 속성값은 아래와 같은 코드를 사용해서 this에 연결되게 된다. 객체의 this의 메서드도 연결할 경우, 메서드가 재사용되지 않는 문제가 있기 때문이다. 따라서 메서드는 프로토타입에 연결해서 재사용하는걸 원칙으로 하는데, 화살표 함수를 사용할 경우 함수가 prototype 객체에 저장되지 않기 때문에 메모리 이슈가 생길 수 있다.

코드로 설명하자면 아래와 같다

```js
class A {
	constructor() {
  }
	run() {
		console.log('run');
  }

  fastRun = () => {
  		console.log('fast run');
    }
  }

}

// 위 클래스를 바벨로 변환할 경우 대충 아래와 같은 클래스가 만들어진다

class A {
	constructor() {
    this.fastRun = () => {
			console.log('fast run');
    }
  }

  }
	run() {
		console.log('run');
  }
}

a = new A();
b = new B();

a.fastRun === b.fastRun
> false
b.run === b.run
> true
```

```
Parent.call(this, parameters);
```



https://medium.com/@charpeni/arrow-functions-in-class-properties-might-not-be-as-great-as-we-think-3b3551c440b1