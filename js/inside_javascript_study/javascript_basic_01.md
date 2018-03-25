### 자바스크립트 falsy and truthy rule
- 타입과 마찬가지로 각각의 값은 상속받은 boolean 값을 가지고 있다.
- !!를 사용해서 각각의 값을 boolean 값으로 변환 시킬 수 있다.
- 정확한 boolean 값을 가지고 있어야, !!연산자를 올바로 사용할 수 있다.
- 아래의 값들은 항상 falsy이다.
    - false
    - 0 (zero)
    - '' or "" (빈 스트링)
    - null
    - undefined
    - NaN (e.g. the result of 1/0)
- 아래의 값들은 항상 truthy이다
    - '0' '0'이라는 문자열
    - 'false', 'false'라는 문자열
    - []
    - {} 빈 객체
    - function(){} 빈 함수
    - Infinity(숫자 값 중에 무한대)
- `==` 연산은 사용할때 주의해야할점 몇가지 정리. 
```
false == 0 == 'empty' // true
null == undefined // true
NaN == NaN // false (NaN은 다른 어떤 값이랑도 같지 않다) 
Infinity == ture // false
Infinity == false // false but Infinity는 truthy이다. 이유가 궁금하면 IEEE 754를 참조해 보는 것이 좋다.
```

이렇게 굉장히 햇갈리는 룰을 가지고 있기 때문에, `==`연산보다는 `===`을 사용하는게 좋다.

### Javascript `&&`와 `||` 연산자

자바스크립트내에서 `&&`과 `||` 연산자는 일반적인 프로그래밍 언어들과 다르게 동작한다. MDN에 설명을 그대로 가지고 오면 아래와 같다.
`expr1 && expr2` 
> Returns expr1 if it can be converted to false; otherwise, returns expr2. Thus, when used with Boolean values, && returns true if both operands are true; otherwise, returns false.

만약 앞에 있는 피연산자가 falsy라면 앞에 피연산자를 리턴하고, 그렇지 않으면 뒤에 피연산자를 리턴한다.

`expr1 || expr2`
> Returns expr1 if it can be converted to true; otherwise, returns expr2. Thus, when used with Boolean values, || returns true if either operand is true.

만약 뒤에 있는 피연산자가 truthy라면 앞에 피연산자를 리턴한다, 그렇지 않으면 뒤에 피연산자를 리턴.

ES2015에서는 3가지의 값을 비교할 수 있는 방법을 제공한다.
    - `===`
        - 두개의 값을 비교할때, 타입을 변환하지 않는다.
    - `==`
        - 두개의 값을 비교할때, 타입을 변환한다.
    - `Object.is`
        - `===`과 비슷하게 동작하는데, `NaN`과 `-0` 그리고 `+0`에 대해서는 다르게 동작한다.
        - Object.is(NaN, NaN)는 true를 리턴함
        
참조

- https://www.sitepoint.com/javascript-truthy-falsy/
- https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Logical_Operators
- https://developer.mozilla.org/en-US/docs/Web/JavaScript/Equality_comparisons_and_sameness