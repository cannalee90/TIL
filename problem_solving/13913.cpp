//
// Created by 강호  이 on 2018. 3. 20..
//


#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <tuple>
#include <numeric>

using namespace std;

#define INF 987654321

int MAX_RANGE = 100000;
bool isRange(int here) {
  if(here < 0 || here > MAX_RANGE) return false;
  return true;
}

int main() {
  int n, k;
  cin >> n >> k;
  queue<int> q;
  vector<int> visited(MAX_RANGE + 1, INF);
  vector<int> from(MAX_RANGE + 1, -1);
  vector<int> ans;
  q.push(n);
  ans.push_back(k);
  visited[n] = 0;

  if(n == k) {
    cout << "0" << endl;
    cout << n << endl;
    exit(1);
  }

  while(!q.empty()) {
    int here = q.front();
    q.pop();
    int next = here + 1;
    int dis = visited[here];
    if(isRange(next) && visited[next] > dis + 1) {
      visited[next] = dis + 1;
      from[next] = here;
      q.push(next);
    }
    int back = here - 1;
    if(isRange(back) && visited[back] > dis + 1) {
      visited[back] = dis + 1;
      from[back] = here;
      q.push(back);
    }
    int teleport = here * 2;
    if(isRange(teleport) && visited[teleport] > dis + 1) {
      visited[teleport] = dis + 1;
      from[teleport]= here;
      q.push(teleport);
    }
  }
  int tmp = k;
  while(from[tmp] != -1) {
    ans.push_back(from[tmp]);
    tmp = from[tmp];
  }
  cout << visited[k] << endl;
  for(auto i = ans.rbegin(); i < ans.rend(); i++) {
    cout << *i << ' ';
  }
}

