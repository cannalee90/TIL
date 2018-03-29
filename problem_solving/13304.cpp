//
// Created by 강호  이 on 2018. 3. 27..
// 원래 다이나믹 문제인데 만약에 특정 조건이 나오면 그리디로 풀 수 있다.

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

#define INF 987654321
int n, m, c;

int cal(int num, int k) {
  int ret = 0;
  ret += (num) / k;
  ret += ((num % k) ? 1 : 0);
  return ret;
}


int main() {
  int student[7][2] = {};
  int n, k;
  int ans = 0;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    student[b][a]++;
  }
  for(int i = 1; i <= 6; i++) {
    if(i % 2 == 0) {
      continue;
    }
    int youngMan = student[i][0];
    int oldMan = student[i + 1][0];
    int youngGirl = student[i][1];
    int oldGirl = student[i + 1][1];
    if(i == 1) {
      ans += cal(youngMan + oldMan + youngGirl + oldGirl, k);
    } else {
      ans += cal(youngMan + oldMan, k);
      ans += cal(youngGirl + oldGirl, k);
    }
  }
  cout << ans << endl;
}

