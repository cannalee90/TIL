//
// Created by 강호  이 on 2018. 3. 27..

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <tuple>
#include <map>
using namespace std;

#define INF 987654321
int n, m, c;

int main() {
  int n, k;
  int ans = 0;
  int idx = 0;
  vector<int> coins;
  cin >> n >> k;
  coins.assign(n, 0);
  idx = n - 1;
  for(int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  while(k) {
    if (k >= coins[idx]) {
      k -= coins[idx];
      ans++;
    } else {
      idx --;
    }
  }
  cout << ans << endl;
}

