### 커링

커링이란 특정 함수에서 정의된 인자의 일부를 넣어 고정시키고, 나머지를 인자로 받는 새로움 함수를 만드는것을 의미한다.

```
function add(x) {
  return function(y) {
    return x + y;
  }
}
```

```
function calculate(a, b, c) {
  return a * b + c;
}

function curry(func) {
  var args = Array.prototype.slice.call(arguments, 1);
  
  return function() {
    return func.apply(null, args.concat(Array.prototype.slice.call(arguments)));
  }
}
```

```
Function.prototype.curry = function() {
  var fn = this;
  var args = Array.prototype.slice.call(arguments);
  return function() {
    return fn.apply(this, args.concat(Array.prototype.slice.call(arguments)));
  }
}
```

`curry` 함수의 프로토타이핑

```
Function.prototype.bind = function(thisArg) {
  var fn = this;
  var slice = Array.prototype.slice;
  var slice.call(arguments, 1);
  return function() {
    return fn.apply(thisArg, args.concat(slice.call(arguments)));
  }
}
```

`bind` 함수
- 커링 기법을 활용한 함수이다. 함수를 호출할 때 바인딩시킬 객체를 사용자가 넣어주는 것.

```
if(!Function.prototype.bind) {
  Function.prototype.bind = function(oThis) {
    if(typeof this !== 'function') {
      throw new TypeError("Function.prototype.bind - what is trying to be bound is not callable");
    }

    var aArgs = Array.prototype.slice.call(arguments, 1);
    var fToBind = this;
    var fNOP = function() {};
    var fBound = function() {
      return fToBind.apply(this instanceof fNOP && oThis ? this : othis, aRgs.concat(Array.prototype.slice.call(arguments)));
    };
    fNOP.prototype = this.prototype;
    fBound.prototype = new fNOP();
    return fBound;
  }
}
```

래퍼

특정 함수를 자신의 함수로 덮어쓰는 것을 말한다. 오버라이드와 유사한 방법이다.

```
function wrap(object, method, wrapper) {
  var fn = object[method];
  return object[method] = function() {
    return wrapper.apply(this, [fn].cocat(Array.prototype.slice.call(arguments)));
  }
}

Function.prototype.original = function(value) {
  this.value = value;
  console.log("value : " + this.value);
}

var mywrap = wrap(Function.prototype "original", function(orig_func, value) {
  this.value = 20;
  orig_func(value);
  console.log("wrapper value : " + this.value);
});

var obj = new mywrap("zzoon");
```

이렇게 될 경우 return 되는 this가 처음 넘어온거와 다르기 때문에 [fn.bind(this)]로 수정한다. 기존에 재공되는 함수에서 사용자가 원하는 로직을 추가하고 싶거나, 기존에 있던 버그를 피할때 사용된다.