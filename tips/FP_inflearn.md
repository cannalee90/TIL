### 1강

순수함수

- 반환 되는 값은 인자로 주어지는 값에만 영향을 받는다. 프로그램의 상태나 외부의 어떤 값에도 영향을 받지 않는다.
- 부수효과를 만들지 않는다. 즉 외부의 값을 영향을 미치거나 혹은 영향을 받지 않고 동일한 인풋에 대해서 동일한 값을 반환한다. 사이드 이펙트의 종류는 아래와 같다.

  - Making a HTTP request
  - Mutating data
  - Printing to a screen or console
  - DOM Query/Manipulation
  - Math.random()
  - Getting the current time

외부의 영향을 받지 않고 인자로 주어지는 값이 중요하므로 평가 시점이 중요하지 않다. 이 때문에 외부 API를 다루는 일이 많은 자바스크립트에서 많이 쓰인다.