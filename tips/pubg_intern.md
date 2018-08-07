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