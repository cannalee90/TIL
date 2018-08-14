## 3rd Week

#### 월요일 

- 간단한 api처럼 한번의 call에서 모두 정리되는게 아니라 여러개를 조합 해야지 내가 원하는 데이터를 만들어서 사용한다. 이 작업은 reselect를 사용해서 진행한다.
- 현재 mission 데이터들이 `weekly.ts30` `weekly.ts60` `weekly.special`과 같은 형식으로 들어온다. 이것이 잘못 변형되서 `weekly0` `weekly1`과 같은 형식으로 들어온다. 이를 제대로 변환해야 하는데, 추후에 battlepass에서 `weekly1` `weekly12`와 같은 것도 처리해줘야 한다.
- websocket은 보는 방식이 좀 다른다. network -> ws -> frame에서 어떤식으로 서버로 들어오는지 확인
- progress bar는 대충 이와 같이 진행하면 된다
https://jsfiddle.net/cannalee90/pcwudrmc/38308/


#### 화요일

- 새로운 아이템을 받으면 조금 다른 방식으로 동작한다.
- `switch`에서 여러개의 case를 한번에 다룰 수 있다. https://stackoverflow.com/questions/13207927/switch-statement-multiple-cases-in-javascript
- table 형태를 직접 구현할 경우 양끝에 border 때문에 귀찮아지는 경우가 있다. 이럴대 깔끔하게 코딩하는 방법은 다음과 같다.
```scss
.list {
  border: 1px solid #fff;
  .item {
    &:not(:last-child) {
      border-bottom: 1px solid #fff;
    }
  }
}

```
https://jsfiddle.net/cannalee90/pcwudrmc/38789/

### 목요일

1. 만약에 class에서 속성이 정의되지 않았는데, 인스턴스의 값을 대입하면 제대로 값이 넣어지지 않는다. 이걸로 한참동안 해맴

2. `reselect`가 언제 새롭게 정의되는지에 대해서 다시 정리해보자

> Reselect provides a function createSelector for creating memoized selectors. createSelector takes an array of input-selectors and a transform function as its arguments. If the Redux state tree is mutated in a way that causes the value of an input-selector to change, the selector will call its transform function with the values of the input-selectors as arguments and return the result. If the values of the input-selectors are the same as the previous call to the selector, it will return the previously computed value instead of calling the transform function.

`createSelector`를 사용해서 memoized selector를 만드는데 이 함수는 input-selector의 배열을 인자로 받는다. 만약 리덕스의 상태 트리가 input-selector의 값들을 바뀌는 대로 변환한다면, selector는 transform 함수를 input-selector의 인자로 사용하면서 결과를 받는다. 만약 input-selectors의 값이 이 전과 같다면 이전에 계산했던 값을 다시 반환한다. 결국 중간에 캐쉬된 값을 가지고 있고, 그값을 반환하므로써 `mapStateToProps`이 일제히 호출하는 것을 막아준다.

## 4th Week

### 

- element의 `positon` 속성을 `absolute`로 바꾼뒤, `top`과 같은 속성을 설정해주지 않으면 제대로 렌더링 되지 않는다
- typescript에서 클래스 속성의 기본값을 설정해주지 않으면 `Object.hasOwnProperty.call(this, key)`의 조건이 생각했던 것처럼 작동되지 않는다.
- class에 없는 property를 강제로 추가해도 그 인스턴스의 해당 속성이 제대로 먹히지 않는다.
