# How Javascript works

### [How JavaScript works: an overview of the engine, the runtime, and the call stack Part - 1](https://blog.sessionstack.com/how-does-javascript-actually-work-part-1-b0bacc073cf)

![stack](./memory_stack_v8.png)

- Google v8엔진은 크롬이랑 node.js에서 사용중
- v8 엔진은 크게 두가지 컴포넌트 `memory heap`과 `call stack`으로 이루어져 있다.

![engine](./js_engine_digaram.png)

- `DOM`, `AJAX`, `setTimeout`같은 Web API는 engine에서 제공하는것이 아니고 브라우저에서 제공해준다.
- `callback queue`와 `event loop` 또한 잊으면 안된다.

![callstack](./callstack.png)

- `callstack`은 프로그램에 어떤 상태인지 알려주는 자료구조이다.
- 처음엔 비어있지만, 함수를 실행하게 되면 콜 스택에 하나씩 `stack frame`이 쌓이게 된다.
- 각각의 entry는 `stack frame`이라고 한다.

```js
function foo() {
    throw new Error('SessionStack will help you resolve crashes :)');
}

function bar() {
    foo();
}

function start() {
    bar();
}

start();
```

`exception`이 발생하면 `stack trace`가 실행된다.

stack의 한도 이상의 `stack frame`이 쌓이게 되면 `stack overflow`가 발생한다.(maximum call stack size exceeded)

자바스크립트는 싱글 쓰레드로 동작하기 때문에, 특정 작업이 오래걸리게 되면 브라우저에서 렌더링을 할 수 없게 된다. 이에 대한 해결책으로 자바스크립트는 비동기 콜백이라는 방식으로 문제를 해결하게 된다.


### [How JavaScript works: inside the V8 engine + 5 tips on how to write optimized code](https://blog.sessionstack.com/how-javascript-works-inside-the-v8-engine-5-tips-on-how-to-write-optimized-code-ac089e62b12e)

#### Javascript Engine

자바스크립트 엔진은 자바스크립트 코드를 실행하는 프로그램 또는 인터프리터이다. JS Engine은 스탠다드 인터프리터로 구현되거나 자바스크립트를 바이트코드로 바꾸는 just-in-time 컴파일러 형태로 구현할 수도 있다.

구글이 만든 v8 engine은 c++로 구현되어 있으며, 다른 엔진들과 다르게 Node.js runtime에 사용된다.

#### 자바스크립트 엔진이 만들어진 이유

V8은 브라우저내에서 JS 퍼포먼스를 향상시키기 위해서 처음에 만들어졌다. 성능을 향상시키기 위해서는 JS 코드를 interpreter 방식이 아닌 JIT 방식을 사용해서 실행해야 했는데, 다른엔진들과 다르게 V8은 bytecode나 intermeidate code를 생성하지 않는다.

#### V8 used to have two compilers

V8은 두가지 컴파일러를 사용한다.

full-codegen - 간단하고 빠른 컴파일러. 상대적으로 느린 머신코드를 생성
Crankshaft - 좀 더 복잡한 JIT 컴파일러. 상대적으로 빠르고 최적화가 잘 되어 있는 코드를 생성한다

또한 V8은 여러개의 쓰레드를 내부적으로 사용한다.

- 메인쓰레드는 일반적으로 코드를 가져오고, 컴파일하고 실행하는 작업을 수행한다. 
- 컴파일링을 위한 쓰레드가 존재한다. 이 쓰레드는 메인쓰레드가 실행되는 동안 코드를 최적화 한다.
- 몇개의 쓰레드는 가비지 컬렉터를 한다.
- 프로파일러 쓰레드는 어떤 메소드에 코스트가 큰지 분석하고 해당 컴파일러가 해당 메소드를 최적화하도록 런타임에게 알려준다.

자바스크립트가 처음 실행되면 V8은 full-codegen(최적화 x)을 사용해서 빠르게 코드를 실행하게 된다. 이방식을 통해서 V8은 intermeidate byte code를 사용하지 않고도 코드를 실행할 수 있다.

코드를 실행하면 profiler 쓰레드가 최적화에 대한 정보를 수집하게 된다.

다음으로, 다른 쓰레드에서 Crankshaft가 최적화를 수행하게 된다. Crankshaft가 Javascript abstract syntax tree를 hig-level static single-assignemnt로 변환하면서 최적화를 수행하게 된다. 대부분의 최적화가 이 레벨에서 이루어진다.

### Inlining

첫번째 최적화는 inlinng이다. 이때 최대한 많은 코드를 inlining 하려고 노력한다. 인라이닝은 함수가 호출되는 부분을 호출되는 함수의 내용으로 교체하는 작업을 뜻한다.

![](./inline.png)

### Hidden class

자바스크립트는 prototype-based 언어이다. 또한 객체를 만든다음 프로퍼티를 쉽게 추가하고 삭제할 수 있는, 다이나믹 프로그래밍 언어이다.

대부분의 자바스크립트 인터프리터는 해쉬함수 기반의 dicationary-like 구조를 사용해서 객체의 속성값을 메모리에 저장한다. 이러한 구조에서는, 객체의 속성에 접근하는 연산이 자바나 시샾같은 non-dynamic programming language에 비해서 코스트가 크다. 자바에서는 모든 오브젝트의 레이아웃이 컴파일 전에 고정되어 있기 때문에, 런타임에 동적으로 속성을 추가하거나 제거할 수 없다. 따라서 모든 속성의 값(혹은 포인터가) 모두 메모리안에 있는 continuous-buffer에 고정된 offset을 가지고 저장된다. 각각의 offset길이는 속성의 type따라서 쉽게 계산된다. 속성의 타입이 런타임에도 바뀔수 있는 자바스크립트에서는 이러한 방식이 불가능하다.

dictionary 구조를 사용해서 메모리에서 값을 찾는건 매우 비효율적이기 때문에 V8은 hidden classes를 사용한다. hidden classes는 자바의 클래스와 매우 비슷하지만 런타임에 실행된다는 점이 다르다.

```js
function Point(x, y) {
    this.x = x;
    this.y = y;
}
var p1 = new Point(1, 2);
```

`new Point(1,2)` 코드가 수행되면, V8은 `C0`이라는 hidden class를 새롭게 만들게 된다. 이때 어떠한 속성도 없는 상태이기 때문에 `C0`은 비어있는 상태이다. `this.x = x` 