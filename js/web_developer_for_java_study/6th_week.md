# DOM

`DOM` - html과 xml 문서에 대한 API, 문서를 노드의 계층 구조 트리로 표현하며 개발자는 페이지의 추가, 제거, 수정합니다.

`요소` - element
`속성` - property

### 10.1.1 Node 타입

- DOM 레벨 1에는 Node라는 인터페이스가 있는데 DOM에 존재하는 노드 타입은 모두 이 인터페이스를 구현합니다.
- 익스를 제외한 모든 브라우저에서 Node 타입에 접근할 수 있고, 자바스크립트의 노트 타입은 모두 Node를 상속합니다.
- 각 노드에는 `childNodes` 프로퍼티가 있는데, 이 프로퍼티에는 `NodeList`가 저장됩니다
  - `NodeList`는  배열 비슷한 객체로써 `length`가 있고 `[]`로 접근 가능하지만 Array가 아니다
  - `var arrayofNodes = Array.prototype.splice.call(sodeNode.childNodes, 0);`
  - 익스8을 제외하고 모든 브라우저에서 동작합니다.
  - 위 방법이 동작하지 않으면 `for` 구문을 사용해서 array에 푸쉬해준다.
- 각 노드는 `previousSibling` 및 `nextSibling` 프로퍼티가 존재한다. 만약 자신이 유일한 노드라면 위에 두개의 값은 `null`이 된다.
- 그밖에 `firstChild`, `lastChild`, `parentNode`, `ownerDocument` 등등이 있다.
- 노드조작을 하는 method는 다음과 같다
  - `appendChild()`
  - `insertBefore()`
    - 기준 노드가 null이면 `appendChild()`와 동일하게 동작한다.
  - `replaceChild()`
  - `removeChild()`
  - `cloneNode()`
    - 매개변수로 하나 넘겨받는데, true를 넘겨받을 경우 자손 노드까지 복제할지 나타낸다
    - 복제된 노드는 document에 소유지만 부모 노드가 할당되지 않는다. 즉 고아노드이다.
  - `normalize()`는 문서 서브트리에 존재하는 텍스트 노드를 다룹니다. 

### 10.1.2 

자바스크립트는 문서 노드를 Document 타입으로 표현합니다. 브라우저에서 전체 HTML 페이지를 표현하는 문서 객체는 HTMLDocument의 인스턴스이며 HTMLDocument는 Document를 상속합니다. document 객체는 widnow의 프로퍼티이므로 전역에서 접근할 수 있습니다. 그리고 다음 특징을 가집니다
- nodeType == 9
- nodeName == `#document`
- nodeValue == null
- parentNode == null
- ownerDocument == null
- 자식 노드로 documentType(최대 1), Element(최대1), Processing Instruction, Comment를 가질 수 있습니다.
```
var html = document.documentElement;
html === document.childNodes[0];
> true;
html === doument.firstChild;
> true;
```

document 객체는 HTMLDocument의 인스턴스이므로 `body` 요소를 직접적을 가르키는 `body` 프로퍼티를 갖습니다. 

`DocumentType`은 `<!DOCTYPE>`에 대한 정보를 리턴하지만 브라우저마다 매우 다르기 때문에 사용하기가 어렵습니다.


#### 문서정보

`document` 객체는 `HTMLDocument`의 인스턴스이므로 표준 `Document` 객체에는 존재하지 않는 프로퍼티를 여럿 가지는데, 이들 프로퍼티는 현재 불러들일 웹 페이지에 대한 정보입니다. 이 정보는 모두 request `HTTP` 해더에 들어있으며 이들 프로퍼티를 통해 자바스크립트에서 사용하는 것 이니다. 이중 스크립트에서 설정할 수 있는 프로퍼티는 domaind이고 보안 문제 때문에 domain 값에는 몇가지 제한이 있습니다.

1. `title`
2. `URL`
3. `referrer`


#### element 위치

- `getElementById()`: Element반환
- `getElementsByTagName()`:  NodeList반환
- `getelementByName()`: 주로 라디오 버튼에 가장 자주 사용합니다.
- `anchors`: name 속성이 있는 `<a>` 요소를 모두 가져옵니다
- `forms`: `<forms>` 요소를 모두 가져옵니다.
- `images`: `<img>` 요소를 모두 가져옵니다.
- `links`: `<a>` href 속성이 있는 요소를 모두 가져옵니다.

### 10.1.3 Element 타입

Element 타입은 XML/HTML 요소를 표현하며 이를 통해 태그 이름이나 자식, 송석 같은 정보에 접근이 가능합니다. Element 노드는 다음과 같은 특징이 있습니다.

- `nodeType` == 1
- `nodeName` == 요소의 태그 이름
- `nodeValue` == null
- `parentNode`는 Document 또는 Element입니다.
- 자식노드로는 `Element` `Text` `Comment` `ProcessInstruction` `CDATA Section` `Entity Reference`를 가질 수 있습니다.

#### HTML Element
 
 html element는 HTMLElement  타입을 통해 표현됩니다. Element를 직접적으로 상속하며 몇가지 프로퍼티가 추가됩니다. 다음은 표준 속성들입니다.
 - `id`
 - `title`
 - `lang`
 - `dir`
 - `className`: `class`가 예약어이기 때문에..

 이 요소에 기록된 정보는 모두 자바스클비트 코드를 통해 가져오고 수정할 수 있습니다.

#### 속성얻기

- `getAttribute()` `setAttribute` `removeAttribute()`를 사용해서 속성을 다룰수 있습니다.
- DOM 요소에 커스텀 프로퍼티를 추가해도 요소에 자동으로 속성이 추가되지는 않습니다.

#### 요소 생성
 
`document.createElement()` 메소드를 통해서 새 요소를 생성할 수 있습니다. 이 메소드는 생성할 element의 태그 이름 하나만 매개변수로 받습니다. HTML에서는 태그 이름에 대소문자를 구분하지 않씁니다. 메서드는 새 오소의 속성을 조작하고 ownDocument 프로퍼티를 설정하고 자식요소를 추가할 수 있습니다.

### 10.1.4 Text 타입

Text 노드는 Text 타입으로 표현됩니다. HTML 코드는 포함할 수 없습니다.
- nodeType == 3
- nodeName == '#text'
- nodeValue는 노드에 포함된 텍스트
- parentNode는 Element입니다


다음은 노드의 텍스트를 조작하는 메서드입니다.
- `appendData(text)`
- `deleteData(offset, count)`
- `insertData(offset, text)`
- `replaceData(offset, count, text)`
- `splitText(offset)`
- `substringData(offset, count)`
- `length`

기본적으로 컨텐츠를 가질 수 있는 element는 모두 최대 하나의 텍스트 노드를 가질 수 있습니다.
새 택스트 노드를 생성할 때는 `document.createTextNode()` 메서드를 사용합니다.
단순한 텍스트 문자열은 모두 텍스트 노드로 표현 가능하기 때문에 형제 텍스트 노드를 하나로 합치는 메서드인 `normizlize()`가 있습니다.

### 10.1.5 Comment 타입

주석은 DOM에서 comment 타입으로 표현됩니다. Comment 노드에는 다음과 같은 특징이 있습니다.
- nodeType == 8
- nodeName == #comment
- nodeValue는 주석 컨텐츠
- parentNode는 Document또는 Element입니다
- 자식 노드는 가질 수가 없습니다

대부분 Text 타입에 있는 문자열 메서드를 대부분 갖고 있지만 splitText()는 예외입니다.

### 10.1.6 CDATASection 타입

CDATA 섹션은 XML 기반 문서 전용이며 CDATASection 타입으로 포현됩니다.

### 10.1.7 DocumentType 타입

DocumentType 타입은 자주 쓰이지 않으며 이를 지원하는 웹 브라우저는 파이어폭스와 사파리, 오페라뿐입니다.

### 10.1.8 DocumentFragment 타입

DocumentFragment 타입은 마크업에 표현되지 않는 유일한 노드타입입니다.

문서 버퍼를 문서에 직접 추가할 수는 없습니다. 문서 버퍼는 문서에 추가할 노드들의 저장소 구실을 합니다.

## 10.2 DOM 다루기

### 10.2.1 동적 스크립트 

`<script>` 요소는 자바스크립트 코드를 페이지에 삽입하는데, src 속성으로 외부 파일을 불러오거나 요소 안에 직접 스크립트 텍스트를 쓸 수 있습니다. 동적 스크립트란 페이지를 불러오는 시점에는 존재하지 않지만 추가적으로 삽입한 스크립트를 말합니다.

이 노드를 생성하는 코드는 다음과 같습니다

```js
var script = document.createElement('script');
script.type = 'text/javascript';
script.src = 'client.js';
document.body.appendChild(script);
```

일단 불러오면 다른 스크립트와 똑같이 사용할 수 있습니다. 그런데 한가지 문제는 스크립트를 불러올 때 완료 시점을 정확히 알 수 없습니다. 브라우저 따라 몇가지 이벤트를 이용할 수 있습니다.

### 10.2.2 동적 스타일

```js
var link = document.createElement('link');
link.rel = 'stylesheet';
link.type = 'text/css';
link.href = 'style.css';
var head = document.getElementsByTagName('head')[0];
head.appendChild(link);
```

- 이 코드는 헤드에 추가해야 합니다
- 스타일을 불러오는 과정이 비동기적으로 이루어지므로 자바스크리브 코드 실행 순서와는 무관하게 로드됩니다. 
