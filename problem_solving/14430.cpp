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
int mmap[310][310];
int data[310][310];

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> mmap[i][j];
      data[i][j] = -1;
    }
  }
  data[1][1] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      data[i][j] = max(data[i-1][j] + mmap[i][j], data[i][j-1] + mmap[i][j]);
    }
  }
  cout << data[n][m] << endl;
}

