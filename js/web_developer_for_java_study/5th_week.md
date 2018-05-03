# 8장 브라우저 객체 모델

## 8.1 브라우저 객체 모델

window 객체는 브라우저 창의 자바스크립트 인터페이스 구실을 하고 다른 한편으로는 ECMAScript Global 객체로 기능합니다.

`Bom`
- Browser Object Model
- Browsers feature a Browser Object Model (BOM) that allows access and manipulation of the browser window. Using the BOM, developers can move the window, change text in the status bar, and perform other actions that do not directly relate to the page content.
- `history` `location` `navigator` and `screen` 

`Dom`
- Document Object Model
- The Document Object Model (DOM) is an application programming interface (API) for HTML as well as XML.

현재는 별 차이가 없다.

### 8.1.1 전역스코프

window 객체가 ECMAScript의 global 객체 구실을 하므로 전역에서 선언한 변수와 함수는 window 객체의 프로퍼티 및 메서드가 됩니다. 따라서 전역에서 선언한 `this.age`와 `window.age`는 같은 결과를 표현합니다.

또한 전역변수는 delete 연산자로 제거할 수 없지만 window에 직접 정의한 프로퍼티는 가능합니다. 왜냐하면 var 연산자를 써서 window에 추가한 프로퍼티는 [[Configurable]] 속성이 false로 지정되기 때문.

선언한 적 없는 변수에 접근하려면 에러가 발생하지만, window의 속성으로 접근하면 에러가 발생하지 않습니다.

### 8.1.6 인터벌과 타임아웃

브라우저에서 자바스크립트는 단일 스레드로 실행된다.(그렇다고 정말 단일 스레드만을 사용하지 않는다) 하지만 타임아웃과 인터벌을 통해 코드가 특정 실행되게끔 조절할 수 있습니다.

`window.setTimeout(fn, milsec)` `window.setInterval(fn, milsec)`

자바스크립트 코드를 나타내는 문자열처럼도 가능하고 함수도 가능하지만 문자열을 넘기는 것은 성능이 떨어집니다.

대기시간은 코드가 실행될 때까지의 시간은 아니고, 큐에 추가될 시간을 뜻합니다.

`setTimeout()`을 호출하면 해당 타임아웃의 숫자형 ID를 반환합니다. 이 ID는 코드의 고유 식별자이며 타임아웃을 취소할 때 사용합니다. `clearTimeout(ID)`를 사용해서 타임 아웃을 취소합니다.

`setInterval(fn, milsec)`도 비슷하게 숫자형 ID를 반환하고 인터벌을 취소할때 사용됩니다.

일반적으로 인터벌은 잘 사용되지 않습니다.

### 8.1.7 시스템 대화상자

브라우저는 `alert()`와 `confirm()` `prompt()` 메서드를 통해 사용자에게 시스템 대화상자를 표시합니다. 이들 대화상자는 동기적이기 때문에 해당 코드가 실행될때는 다른 자바스크립트 코드가 실행되지 않습니다.

`confirm()` 반환형은 true와 false인데 대화상자를 각각 확인을 클릭했을때, 취소 또는 창닫기를 눌렀을때의 반환형입니다.

`prompt()`를 통해서는 텍스트 박스 값을 반환합니다.

크롬과 오페라에서는 실행중인 스크립트가 시스템 대화상자를 두 개 이상 만든다면 첫번째 대화상자 다음부터는 사용자가 이들을 차단할 수 있도록 하는 체크박스를 제공합니다.

`window.print()`와 `window.find()`를 사용해서 `인쇄` 대화상자와 `찾기` 대화상자를 표시할 수 있습니다.

## 8.2 location 객체

location은 BOM에서 가장 유용한 객체 중 하나입니다. location 객체는 winodw의 프로퍼티의 동시엔 document의 프로퍼티입니다.

| Peroperty     | 예제      | 설명           |
| ------------- |----------|------------------------------------------------------|
| hash          | #content | # 기호 다음에 문자가 오는 형태의 URL해쉬. URL에 해쉬가 없다면 빈 문자열입니다.| 
| host          | www.wrox.com:80 | 서버 이름과 포트번호(있다면)입니다.|
| hostname      | www.wrox.com    | 포트 번호를 제외한 서버 이름입니다.|
| href          | https://www.wrox.com | 현재 페이지의 완전한 URL입니다. location의 toString() 메소드는 이 값을 반환합니다.|
| pathname      | "/post/1"       | URL에 포함된 디렉터리 및 파일 이름입니다.|
| port          | 80 | URL의 요청 포트(존재한다면)입니다. URL에 포트가 없으면 이 프로퍼티는 빈 문자열을 반환합니다.|
| protocol      | "https:"  | 페이지에서 사용하는 프로토콜입니다. 일반적으로 `http:`나 `https:`중 하나입니다. 프로토콜을 스키마라고 부르기도 합니다.| 
| search        | "?q=javascript | URL의 쿼리스트링 부분입니다. 물음표 기호로 시작하는 문자열을 반환합니다.|

### 8.2.1 쿼리스트링 확장

location에 들어 있는 정보는 대부분 쉽게 접근할 수 있지만, URL 정보 중 쿼리스트링은 다루기 어려운 형태로 제공되기 때문에 아래의 코드로 분리할 수 있다. 

```js
function getQueryStringArgs() {
  var qs = (location.search.length > 0 ? location.search.substring(1) : "");
  args = {};
  items = qs.length ? qs.split("&") : [],
  item = null;
  name = null;
  value = null;
  len = items.length;
  for(let i = 0; i < len; i++) {
    item = items[i].split("=");
    name = decodeURIComponent(item[0]);
    value = decodeURIComponent(item[1]);
    if(name.length) {
      args[name] = value;
    }
  }
}
```

개인적으로 주로 사용하는 [query-string](https://github.com/sindresorhus/query-string/blob/master/index.js) package와 비교해보자.
- sorting 지원
- query-string에서 리턴되는 object는 prototype이 없음
- key를 기준으로 sort되서 리턴된다

### 8.2.2 location 조작

다양한 방법으로 location 객체를 조작해서 페이지를 이동할 수 있습니다.

다음 3개의 메서드는 똑같이 동작합니다.

- `location.assign("http://www.naver.com")`
- `window.location = "http://wrox.com"`
- `location.href = "http://wrox.com"`(가장 많이 쓰인다)

location 객체의 프로퍼티를 변경하면 현제 페이지에도 영향이 있습니다. 하지만 hash 프로퍼티를 바꿀때는 예외입니다.

위에 3가지 방법으로 url을 수정하면 브라우저의 히스토리 스택에 기록이 남아서 사용자가 뒤로가기 버튼을 클릭해 이전 페이지로 돌아갈 수 있습니다. 하지만 `replace()` 메서드를 쓰면 뒤로가기 버튼을 클릭해 이전 페이지로 돌아갈 수 없습니다.

`reload()`를 매개변수 없이 호출하면 가능한 한 효과적인 방법으로 다시 읽습니다.
`realod(true)` 항상 서버 호출

# 기능탐지

- 갑자기 브라우저가 지원을 할 수도 있고, 안할 수도 있기 때문에, 브라우저 디텍팅 보다는 기능탐지를 사용하게 된다.

```js
if (object.propertyInQuestion) {

}
```
기능탐지의 두가지 원칙
- 같은 결과를 얻을 수 있는 가장 일반적인 방법을 먼저 테스트해야 합니다.
  - ex) `document.getElementById()`를 `document.all`보다 먼저 테스트해야 한다. ㅂ
- 사용하려는 기능을 정확히 테스트 해야 한다.
- 브라우저와 객체를 가리지 않고 함수의 존재 여부를 테스트하려면 다음 함수를 써야 한다.
```js
// it would return true or false
function isHostMethod(object, property) {
  var t = typeof object[property];
  return t == 'function' || (!!t=='object' && object[property]) || t == 'unknow';
}
```
- 브라우저 탐지보다는 좀 더 효율적인 코드를 작성할 수 있지만 믿지말자.
- 브라우저 탐지는 그냥 라이브러리를 쓰자..
