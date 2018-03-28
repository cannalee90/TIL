//
// Created by 강호  이 on 2018. 3. 27..
// 원래 다이나믹 문제인데 만약에 특정 조건이 나오면 그리디로 풀 수 있다.

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
  cin >> n;
  queue<int> q;
  while(n--) {
    string keyword;
    int num;
    cin >> keyword;
    if(keyword == "push") {
      cin >> num;
      q.push(num);
    } else if(keyword == "front") {
      if(q.size()) {
        cout << q.front() << endl;
      } else {
        cout << "-1" << endl;
      }
    } else if(keyword == "back") {
      if(q.size()) {
        cout << q.back() << endl;
      } else {
        cout << "-1" << endl;
      }
    } else if(keyword == "size") {
      cout << q.size() << endl;
    } else if(keyword == "empty") {
      if(q.empty()) {
        cout << "1" << endl;
      } else {
        cout << "0" << endl;
      }
    } else if(keyword == "pop") {
      if(q.size()) {
        cout <<  q.front() << endl;
        q.pop();
      } else {
        cout << "-1" << endl;
      }
    }
  }
}

