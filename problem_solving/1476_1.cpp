//
// Created by  이강호 on 2018. 3. 11..
//
// 중국인의 나머지 정리를 이용해서 문제를 풀 수 있다.
// http://joonas.tistory.com/23 이 두곳을 참조해서
// https://namu.wiki/w/%EC%A4%91%EA%B5%AD%EC%9D%B8%EC%9D%98%20%EB%82%98%EB%A8%B8%EC%A7%80%20%EC%A0%95%EB%A6%AC#fn-10
// https://www.youtube.com/watch?v=ru7mWZJlRQg
//
// (28 * 19 * e) % 15 == (532 * e) % 15 == (7 * er) % 15 == 1
// (15 * 19 * s) % 28 == (285 * s) % 28 == (5 * sr) % 28 == 1
// (15 * 28 * m) % 19 == (420 * m) % 19 == (2 * mr) % 19 == 1
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long e, s, m;
  long long er = 13, sr = 17, mr = 10;
  long long emax = 15, smax = 28, mmax = 19;
  cin >> e >> s >> m;
  long long ans = ((e * 6916) + (4845 * s) + (m * 4200));
  if (!(ans % 7980)) {
    cout << "7980" << endl;
  } else {
    cout << ans % 7980 << endl;
  }
}
