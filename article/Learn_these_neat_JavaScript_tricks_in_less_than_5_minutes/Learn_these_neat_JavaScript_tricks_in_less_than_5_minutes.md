1. Clearing or truncating an array

배열을 초기화하거나 길이를 줄일때는 length 속성을 조절하면 된다.

```js
const arr = [11, 22, 33, 44, 55, 66];
// truncanting
arr.length = 3;
console.log(arr); //=> [11, 22, 33]
// clearing
arr.length = 0;
console.log(arr); //=> []
console.log(arr[2]); //=> undefined
```

2. Simulating named parameters with object destructuring
만약 config object를 이미 사용하고 있다면 아래와 같은 코드를 사용하고 있을 확률이 높다.
```js
doSomething({ foo: 'Hello', bar: 'Hey!', baz: 42 });
function doSomething(config) {
  const foo = config.foo !== undefined ? config.foo : 'Hi';
  const bar = config.bar !== undefined ? config.bar : 'Yo!';
  const baz = config.baz !== undefined ? config.baz : 13;
  // ...
}
```

named parameters를 시뮬레이트하려고 시도한 오래되고 효과적인 방법이다. 잘 작동되지만 config object를 다루는 방법이 너무 복잡하다. ES2015 object destructuring을 사용하면 언급한 단점을 피할 수 있습니다.
```js
function doSomething({ foo = 'Hi', bar = 'Yo!', baz = 13 }) {
  // ...
}
```
config 오브젝트를 optional하게 만들려면 다음과 같이 하면된다.
```js
function doSomething({ foo = 'Hi', bar = 'Yo!', baz = 13 } = {}) {
  // ...
}
```

3. Object destructuring for array items
배열의 요소를 각각의 변수로 할당할때
```js
const csvFileLine = '1997,John Doe,US,john@doe.com,New York';
const { 2: country, 4: state } = csvFileLine.split(',');
country
> "US"
state
> "New York"
```

4. Switch with ranges
범위로 switch문의 조건을 설정하는 방법
```js
function getWaterState(tempInCelsius) {
  let state;
  
  switch (true) {
    case (tempInCelsius <= 0): 
      state = 'Solid';
      break;
    case (tempInCelsius > 0 && tempInCelsius < 100): 
      state = 'Liquid';
      break;
    default: 
      state = 'Gas';
  }
  return state;
}
```


5. Await multiple async functions with async/await
여러개의 async function을 Promise.all을 사용해서 await 하는 방법

```js
await Promise.all([anAsyncCall(), thisIsAlsoAsync(), oneMore()])
```

6. Creating pure objects

어떠한 메소드나 값을 상속받지 않는 순수한 오브젝트를 만드는 방법

```js
const pureObject = Object.create(null);
console.log(pureObject); //=> {}
console.log(pureObject.constructor); //=> undefined
console.log(pureObject.toString); //=> undefined
console.log(pureObject.hasOwnProperty); //=> undefined
```

7. Formatting JSON code

JSON.stringfy로 간단하게 object를 문자열화 하는 것 보다 많은 것을 할 수 있다. JSON output을 아름답게 만들 수 있다.

```js
const obj = { 
  foo: { bar: [11, 22, 33, 44], baz: { bing: true, boom: 'Hello' } } 
};
// The third parameter is the number of spaces used to 
// beautify the JSON output.
JSON.stringify(obj, null, 4); 
// =>"{
// =>    "foo": {
// =>        "bar": [
// =>            11,
// =>            22,
// =>            33,
// =>            44
// =>        ],
// =>        "baz": {
// =>            "bing": true,
// =>            "boom": "Hello"
// =>        }
// =>    }
// =>}"
```

8. Removing duplicate items from an array
ES2015의 Sets를 spread 연산자와 함께 사용하면서, 쉽게 중복 제거할 수 있다.

```js
const removeDuplicateItems = arr => [...new Set(arr)];
removeDuplicateItems([42, 'foo', 42, 'foo', true, true]);
//=> [42, "foo", true]
```

9. Flattening multidimensional arrays

2차원 배열을 flatten 해주는 코드이다.

```js
const arr = [11, [22, 33], [44, 55], 66];
const flatArr = [].concat(...arr); //=> [11, 22, 33, 44, 55, 66]

//concat method는 2개 이상의 배열을 merge하는 메소드이다.
//인자로 주어진 배열을 얕은 복사하는 방식으로 merge한다
//string이나 numbers boolean 값들은 q
```


중첩된 배열을 flatten 해주는 코드이다.


```js
function flattenArray(arr) {
  const flattened = [].concat(...arr);
  return flattened.some(item => Array.isArray(item)) ? 
    flattenArray(flattened) : flattened;
}

const arr = [11, [22, 33], [44, [55, 66, [77, [88]], 99]]];
const flatArr = flattenArray(arr); 
//=> [11, 22, 33, 44, 55, 66, 77, 88, 99]
```