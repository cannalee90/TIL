//
// Created by 강호  이 on 2018. 5. 12..
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

#define INF 987654321
int n, m, c;
int mustPass;
int target = 'Z' - 'A';
int result = INF;
vector<vector<int> > graph;
vector<bool> visited(100);

void dfs(int cur, int dis, bool mustPassed) {
  if(cur == target && mustPassed) {
    result = min(result, dis);
    return;
  } else if(cur == target) {
    return;
  }
  for(int i = 0; i < graph[cur].size(); i++) {
    int next = graph[cur][i];
    visited[next] = true;
    dfs(next, dis + 1, (mustPass == next) || mustPassed);
    visited[next] = false;
  }
}

int main() {
  char tmp;
  scanf("%d", &m);
  graph.resize(30);
  for(int i = 0; i < m; i++) {
    char c, d;
    int a, b;
    scanf(" %c,%c", &c, &d);
    a = (int)(c - 'A');
    b = (int)(d - 'A');
    graph[a].push_back(b);
  }
  scanf(" %c", &tmp);
  mustPass = tmp - 'A';
  queue<int, int> queue;
  while(!queue.empty()) {

    cur = queue.front().first;
    dis = queue.front().second;
    isPassed = visited[mustPass];
    if(isPassed && cur == target) {
      result = max(result, dis);
      continue;
    }
    for(int i = 0; i < graph[cur].size(); i++) {
      int next = graph[cur][i];
      q.push({next, dis + 1});
    }
  }
  if(result != INF) {
    cout << result << endl;
  } else {
    cout << "-1" << endl;
  }
}



