//
// Created by  이강호 on 2018. 5. 31..
//

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <tuple>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

bool check(int num, int p) {
  int position = pow(2, p);
  if(num & position) {
    return true;
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vi(n);

  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b;
    b--;
    int &ret = vi[b];
    if(a == 1) {
      cin >> c;
      c--;
      int p = pow(2, c);
      ret |= p;
    } else if(a == 2) {
      cin >> c;
      c--;
      int p = pow(2, c);
      if(check(ret, c)) {
        ret -= p;
      }
    } else if(a == 3) {
      ret <<= 1;
      int p = pow(2, 20);
      if(check(ret, 20)) {
        ret -= p;
      }
    } else if(a == 4) {
      ret >>= 1;
    }
  }
  sort(vi.begin(), vi.end());
  vi.erase(unique(vi.begin(), vi.end()), vi.end());
  cout << vi.size() << endl;
}

