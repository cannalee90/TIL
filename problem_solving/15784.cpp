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
  int n, a, b;
  int mmap[1100][1100];
  cin >> n >> a >> b;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> mmap[i][j];
    }
  }
  a--;
  b--;
  for(int i = 0; i < n; i++) {
    if(mmap[i][b] > mmap[a][b] || mmap[a][i] > mmap[a][b]) {
      cout << "ANGRY" << endl;
      exit(0);
    }
  }
  cout << "HAPPY" << endl;
}