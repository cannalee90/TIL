#include <iostream>

using namespace std;

int main() {
  int a, b, v;
  scanf("%d %d %d", &a, &b, &v);
  if(a >= v) {
    printf("1\n");
  } else {
    int daily = a - b;
    int last = v - a;
    printf("%d\n", ((last % daily) == 0 ? (last / daily) + 1 : (last / daily) + 2));
  }
}

// edge 케이스로 v가 a보다 크거나 같을때로 처리해주고
// 마지막날에는 미끄러지지 않으므로, 마지막 날 전까지 필요한 날을 게산한다음 처리