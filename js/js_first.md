#Code School JS



###기본

- 기본적인 사칙연산은 동일하다.
- console을 사용해서 기본적인 코드를 작성할 수 있다.
- 기본적인 사칙연산은 동이랗다.

### Comparators

- 기본적으로 비교자는 동일하다

### STRING

- 스트링은 ""로 선언 가능하다.
- + 를 사용해서 합쳐질 수 있다.(concatenation)
  - 재미있게도 + 연산자가 str.concat()메써드 보다 빠르다.<sup>[1](http://stackoverflow.com/questions/7299010/why-is-string-concatenation-faster-than-array-join)</sup><sup>, [2]()</sup>
- concatenation을 사용할 때 몇가지 주의할 점이 있다.
~~~
> "The meaning of life is" + 42
"The meaning of life is42" (스페이스를 넣어줘야 한다)
~~~

- 몇가지 특수문자(개행, 탭, 쌍따옴표)를 삽입하기 위해서는 \를 앞에 넣어줘야 한다
- js에서는 ==를 사용해서 스트링을 비교할 수 있다.(case sensative)
- .length property를 사용해서 길이를 알아낼 수 있다.

### 변수

- 변수명에는 빈칸이 들어갈 수 없다
- 변수명에 첫번째 글자가 숫자여서는 안된다.
- 변수명으로 언더바 _ 를 사용할 수 있다.
- [valid JS variable name in ES6](https://mathiasbynens.be/notes/javascript-identifiers-es6) 에서 몇가지만 정리해보면
  - await(invalid in ES6 for the reserved word)
  - 변수명으로 유니코드 글자를 사용할 수 있다
- camelcase가 standard
- =를 사용해서 변수에 새로운 값을 대입할 수 있다.
- += *= -= %= 를 사용할 수 있다.
- 변수는 데이터를 가르키는 역활을 한다.
- ++, --와 같은 연산자도 사용이 가능하다.

### 변수 좀 더

- index는 0부터 시작한다.
- charAt(11)은 []연산자와 같은 역활을 한다. [(charAt MDN)](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/String/charAt)
  - ECMAScript 5부터 똑같이 쓰이게 됨. 일부 브라우저에서는 제대로 작동하지 않는다.
  - 만약 문자열의 크기를 넘어선 범위가 들어선다면 빈 문자열을 반환하게 된다.
~~~
> var str = "Hello world"
> str[4]
< "o"
> str.charAt(4)
< "o"
> str.charAt(20)
< ""
~~~
 - 연산할때 연산이 길어지면 연산 중간에 개행이 들어갈 수 있다

 ###JS within File

 - 보통 header안에 아래와 같은 형식으로 삽입한다.

 ~~~
 <script src = "path"></script>
 ~~~

 ### console

 - console.log을 사용해서 브라우저 콘솔창에 출력할 수 있다. [MDN console](https://developer.mozilla.org/en-US/docs/Web/API/Console)
 ~~~
 console.log("Hello world!")
 ~~~

 - console.clear()를 사용하면 콘솔창이 초기화 된다.

 ~~~
 > console.clear()
 ~~~

 - console.error()를 사용하면 콘솔창에 빨간색 에러메세지를 출력할 수 있다.

 ~~~
 > console.error()
 ~~~

 - 그 밖에 다양한 메써드들이 있으니 참고해보자
