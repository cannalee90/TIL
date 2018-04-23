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

```
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


