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
  int helmet = 0;
  int vest = 0;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    helmet = max(helmet, tmp);
  }
  for(int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    vest = max(vest, tmp);
  }
  cout << vest + helmet << endl;
}