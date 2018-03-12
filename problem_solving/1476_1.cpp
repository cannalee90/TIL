//
// Created by  이강호 on 2018. 3. 11..
//
// 중국인의 나머지 정리를 이용해서 문제를 풀 수 있다.
// http://joonas.tistory.com/23 이곳을 참조해서 문제를 풀 었다.
// (28 * 19) ^ a1 mod 15 = 1
// (15 * 19) ^ a2 mod 28 = 1
// (15 * 28) ^ a3 mod 19 = 1
// 각각의 a1, a2, a3의 값을 구해놓고 문제를 풀면 간단하게 풀 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int e, s, m;
  int emax = 15, smax = 28, mmax = 19;
  long long tmp = 28 * 19;
  for(int i = 1; ; i++) {
    cout << tmp << endl;
    if(tmp % emax == 1) {
      cout << i << endl;
      cout << tmp << endl;
      break;
    }
    tmp *= 28 * 19;
  }
//  cin >> e >> s >> m;
}


