### inorder preorder postorder

![](./tree12.gif)

inorder: left, root, right
(42513)
```c++
traversal(int here) {
  traversal(here->left);
  cout << here;
  traversal(here->right);
}
```

preorder: root, left, right
(12453)
```c++
traversal(int here) {
  cout << here;
  traversal(here->left);
  traversal(here->right);
}
```

postorder: left, right, root
(45231)
```c++
traversal(int here) {
  traversal(here->left);
  traversal(here->right);
  cout << here;
}
```


### DFS BFS
depth first search: 깊이 우선 탐색. 주로 스택이나 재귀함수를 사용해서 구현하게 됩니다. O(n + m)

```c++
void dfs(int here) {
  visited[here] = true
  for(int i = 0; i < here.size(); i++){
    int next = here[i];
    if(!here[i]) {
      dfs(next);
    }
  }
}
```

breadth first search: 넓이 우선 탐색. 큐를 사용해서 구현합니다. 특정 깊이를 모두 탐색한 다음 깊이로 넘어가게 됩니다.
O(n + m)

```c++
void bfs() {
  while(que.size()) {
    here = que.front();
    que.pop();
    visited[here] = true
    for(int i = 0; i < here.size(); i++){
      int next = here[i];
      if(!here[i]) {
        que.push_back(next);
      }
    }
  }
}
```

### C++ Set

key 값을 기준으로 의한 정렬이 되어 있어야하고, find, insert, delete 연산이 O(logN)에 수행되어야 하기 때문에, Balanced Binary Search 트리로 작성되어야 합니다. STL에서는 Sorted Associative Container로 분류되고 대부분의 경우 RED-BLACK 트리를 구현해서 사용합니다.

### 바이너리 서치 트리에서 N번째 요소 찾기

만약 전처리를 할 수 없으면 O(n)이다. 만약 전처리를 할 수 있으면 O(h)이다. 전처리를 할 경우 각각의 노드를 루트로 하는 트리의 노드의 수를 저장해 놓으면 이를 기반으로 빠르게 찾을 수 있다.

### 바이너리서치 시간복잡도 분석해보세요

만약 데이터가 정렬되어 있지 않다면 데이터를 정렬해야 하고 랜덤엑세스가 가능한 자료구조여야 한다. 전체 탐색해야 하는 인덱스의 범위를 (0(min), n-1(max))라고 할때 가운데 인덱스에 있는 원소가 찾으려는 원소보다 작다면 찾아야할 원소의 인덱스는 (current, max)에 있다는 것이 보장된다. 그 반대의 경우 (min, current) 역시 보장된다. 비교연산의 시간복잡도가 O(1)이라 할때 최종 시간복잡도는 O(logN)이 된다.

### BIG O

f와 g를 각각 양의 정수를 갖는 함수라 할 때, 만일 어떤 두 양의 상수 a와 b가 존재하고, 모든 n ≥ b에 대하여, f(n) ≤ a*g(n)이면 f(n) = Θ(g(n))

f(n)의 상승률이 a*g(n)의 상승률보다 작다는 것을 의미한다. 함수의 상한을 정해두는 것

### BIG Omega

f와 g를 각각 양의 정수를 갖는 함수라 할 때, 만일 어떤 두 양의 상수 a와 b가 존재하고, 모든 n ≥ b에 대하여, f(n) ≥ a*g(n)이면 f(n) = Ω(g(n))

f(n)의 상승률이 a*g(n)의 상승률보다 크다는 것을 의미한다. 함수의 하한을 정해두는 것.

https://www.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/big-o-notation

### MST의 두가지 알고리즘

신장 트리란 원래 그래프에서 다음 조건을 만족하는 그래프의 서브그래프를 말합니다.

- 원 그래프의 모든 노드를 포함
- 모든 노드가 서로 연결되어 있음
- Tree의 속성을 만족한다.(싸이클이 없고 서로 다른 두 노드의 path는 1개)

이때 그래프의 엣지가 가중치를 가진다고 할때 최소의 비용으로 만들 수 있는 신장트리를 최소 신장트리라고 합니다.

### Insertion Sort

```js
function insertionSort(arr, n) {
  for(var i = 1; i < n; i++) {
    for(var j = i - 1; j >= 0; j--) {
      if(arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1)
      } else {
        break;
      }
    }
  }
  return arr;
}
```

배열의 처음 부분을 sorted array를 만들어 놓고, 새로운 요소들을 삽입하면서 sorted array 내에서 그들의 자리를 찾아가는 구조의 정렬이다. 간단한 구조로 인해서 n의 크기가 작을때 속도가 가장 빠르다고 알려져 있다. O(n^2)

### 선택정렬

```js
function selectionSort(arr, n) {
  for(var i = 0; i < n; i++) {
    var min_idx = i;
    for(var j = i + 1; j < n; j++) {
      if(arr[min_idx] > arr[j]) {
        min_idx = j;
      }
    }
    swap(arr, i, min_idx);
  }
  return arr;
}
```

버블정렬과 비슷한 알고리즘이지만 swap의 횟수를 줄여서 효율을 높인 알고리즘이다. O(n^2)


### Merge Sort

```js
// function mergeArray(arr, left, mid, right) {
//  [left ~ mid - 1), [mid ~ right) 두개의 배열(범위)에서 작은 것을 빼오는 방식으로
//  병합한 배열을 넘겨준다. 하지만 빠르게 처리하기 위해서 arr를 수정한 다음에 병합한 배열을 넘겨준다.
// }

function mergeSort(arr, left, right) {
  if(right - left <= 1) {
    return;
  }
  var mid = parseInt((left + right) / 2);
  mergeSort(arr, left, mid);
  mergeSort(arr, mid, right);
  
  mergeArray(arr, left, mid, right);
  return;
}
```

```js
function merge(left, right) {
  var ret = [];
  while(left.length || right.length) {
    if(left[0] < right[0] || right.length == 0) {
      ret.push(left.shift());
    } else {
      ret.push(right.shift());
    }
  }
  return ret;
}

function mergeSlow(arr) {
  if(arr.length <= 1) {
    return arr;
  }
  var mid = parseInt((arr.length) / 2);
  var left = arr.slice(0, mid);
  var right = arr.slice(mid);
  left = mergeSlow(left);
  right = mergeSlow(right);
  return merge(left, right);
}
```

분할정복 전략을 기초로 만들어진 알고리즘이다. 일단 데이터를 재귀적으로 배열의 크기가 1이 될 때까지 2개로 쪼갠다. 이렇게 분리된 리스트를 병합하는데, 왼쪽과 오른쪽에서 배열에서 작은 것을 하나씩 가져와서 반환시킬 배열에 추가합니다. 왼쪽과 오른쪽 배열의 원소가 모두 없어질때까지 이 작업을 반복한 다음, 새롭게 만들어진 배열을 변환합니다. 이때 새롭게 만들어진 배열은 모두 정렬된 상태이고, 이 작업을 반복하게 됩니다.

O(nlogn);

### Tree Binary Tree 와 Complete Binary tree 그리고 BST, BBST

#### Tree

노드와 엣지로 구성되어 있는 자료구조이다. 아래의 조건을 만족합니다.

- 루트노드를 제외한 모든 노드는 단 하나의 부모노드만을 가진다
- 임의의 노드에서 다른 노드로 가는 경로(path)는 유일하다.
- 회로(cycle)가 존재하지 않는다.
- 모든 노드는 서로 연결되어 있다.
- 엣지(edge)를 하나 자르면 트리가 두 개로 분리된다.
- 엣지(edge)의 수 |E| 는 노드의 수 |V|에서 1을 뺀 것과 같다.

#### Binary Tree

자식의 갯수가 최대 두 개인 노드들로 구성된 트리.

#### Complete Binary Tree

모든 인터널 노드가 두개의 자식을 가지고 있는 이진트리

#### BST

이진트리의 특수한 형태이고 다음의 조건을 만족한다.

- 노드의 왼쪽 서브트리의 노드들은 그 노드의 값보다 작거나 같다
- 노드의 오른쪽 서브트리의 노드들은 그 노드의 값보다 크거나 같다.
- 모든 노드의 서브트리들은 모두 BST이다.

#### BBST

BST의 문제점을 해결하기 위한 자료구조이다. BST의 경우 최악의 경우 시간복잡도가 O(n)까지 늘어날 수 있다. 이런 문제점을 해결하기 위해서 트리의 높이(height)를 조절해준다. 대표적으로 AVL트리와 RB Tree가 있다.

AVL 트리의 조건은 아래와 같다.

트리 T의 모든 내부 노드(internal node) v에 대하여 v의 자식 노드들의 높이 차이가 최대 1이다.

RB 트리의 조건은 아래와 같다. 

1. Root Property : 루트노드의 색깔은 검정(Black)이다.
2. External Property : 모든 external node들은 검정(Black)이다.
3. Internal Property : 빨강(Red)노드의 자식은 검정(Black)이다. 
4. Depth Property : 모든 리프노드에서 Black Depth는 같다. 
5. 모든 노드들은 검정 or 빨강이라는 속성을 가진다.

루프노드와 가장 먼 리프노드의 거리와 가장 가까운 거리가 두배 이하이다.

#### 후위 표기식 계산 with stack

```js
var expr = "ABC*+DE/-";
var input = [ '1', '2', '3', '4', '5' ]
for(var i = 0; i < expr.length; i++) {
  var cur = expr[i];
  if(cur === '*') {
    var last = st.pop();
    last = last * st.pop();
    st.push(last);
  } else if(cur === '/') {
    var last = st.pop();
    last = st.pop() / last;
    st.push(last);
  } else if(cur === '-') {
    var last = st.pop();
    last = st.pop() - last;
    st.push(last);
  } else if(cur === '+') {
    var last = st.pop();
    last = last + st.pop();
    st.push(last);
  } else {
    var idx = parseInt(cur.charCodeAt()) - 65;
    st.push(parseInt(input[idx]));
  }
}
```

