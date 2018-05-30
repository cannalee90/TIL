//
// Created by  이강호 on 2018. 5. 31..
//

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <tuple>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

int main() {
  int n, m;
  int total = 0;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    total += (tmp + 1) / 2;
  }
  if (total >= n) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}