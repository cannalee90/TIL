## Cousera PL Week A

### 강의요약

- 간단한 수업 오리엔테이션
- 실습은 ML이라는 언어로 진행 된다.

### What I learned

- 다음은 ML 언어에 대한 간단한 특징이다
    - 각각의 함수는 단 하나의 argument를 가진다. 각각의 argument는 tuple로 만들어질 수도 있다.
    - `foo(2,3)`은 foo함수에 `(2,3)`이라는 튜플을 적용하라는 의미이다
    - 음수표현은 `~` (not `-`)
    - 실수 나눗셈 연산자는 `div`
    - 불일치는 `<>` (not `!=`)
    - SML은 실수와 정수끼리의 묵시적 변환이 없다.
    - String concatenation은 `^`
    - 주석표현은 `* comment *`
    - SML 인터프리터는 `it`이라는 변수를 사용해서 마지막 input line의 리턴값을 보여준다.

```ML
fun f(x,y) = x * y
* (x,y)라는 튜플을 argument로 가지는 함수 선언(좌변). 우변은 함수의 정의로써 x * y의 값을 리턴한다. *
fun double x = f(x,2)
* double이라는 함수 선언. 이 함수는 x라는 argument를 가진다. 이 함수는 위에 정의한 f(x,y)의 함수의 결과값을 리턴한다.* 
```
### Further Question


### reference

- http://www.cs.cmu.edu/~wklieber/212/2010-08-25.html
- http://www.cs.cmu.edu/~rwh/isml/book.pdf