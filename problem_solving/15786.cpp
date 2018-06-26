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
  string str;
  cin >> n >> m;
  cin >> str;
  for(int i = 0; i < m; i++) {
    string tmp;
    int strIdx = 0;
    int tmpIdx = 0;
    cin >> tmp;
    while(tmpIdx < tmp.size() && strIdx < str.size()) {
      if(tmp[tmpIdx] == str[strIdx]) {
        strIdx++;
      }
      tmpIdx++;
    }
    if(strIdx == str.size()) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }
}