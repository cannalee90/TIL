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


int main() {
  while(true) {
    string line, trim, ans;
    getline (cin, line);

    if(line == ".") {
      break;
    }
    bool flag = true;
    int last = -1;
    for(const auto& cur : line) {
      if(cur == ']' || cur == '[' || cur == '(' || cur == ')') {
        trim.push_back(cur);
      }
    }
    for(const auto& cur: trim) {
      if(cur == ']' && ans.back() == '[') {
        ans.pop_back();
      } else if(cur == ')' && ans.back() == '(') {
        ans.pop_back();
      } else if(cur == '(' || cur == '['){
        ans.push_back(cur);
      } else {
        flag = false;
        break;
      }
    }
    if(ans.empty() && flag) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

}

