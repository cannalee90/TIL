//
// Created by 강호  이 on 2018. 3. 16..
//

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <tuple>

using namespace std;

#define INF 987654321
int n, m, c;
vector<vector<pair<int, int > > > graph;
vector<int> macdonald;
vector<int> starbucks;
int macLimit, starLimit;

vector<int> dijkstra(int start) {
  vector<int> dist(n + 3, INF);
  dist[start] = 0;
  priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int > > > pq;
  pq.push({0, start});
  while(!pq.empty()) {
    int hereDist = pq.top().first;
    int here = pq.top().second;
    pq.pop();
    if(dist[here] < hereDist) continue;
    for(int i = 0; i < graph[here].size(); i++) {
      int there = graph[here][i].first;
      int thereDist = graph[here][i].second + hereDist;
      if(thereDist < dist[there]) {
        dist[there] = thereDist;
        pq.push(make_pair(thereDist, there));
      }
    }
  }
  return dist;
}

int main() {
  int macNum, starNum;
  int macDummy, starDummy;
  int macLimit, starLimit;

  scanf("%d %d", &n, &m);
  graph.resize(n + 3);
  macdonald.resize(n + 3);
  starbucks.resize(n + 3);
  macDummy = n + 1;
  starDummy = n + 2;
  for (int i = 0; i < m; i++) {
    int t1, t2, t3;
    scanf("%d %d %d", &t1, &t2, &t3);
    graph[t1].push_back({t2, t3});
    graph[t2].push_back({t1, t3});
  }
  cin >> macNum >> macLimit;
  for (int i = 0; i < macNum; i++) {
    int t1;
    cin >> t1;
    macdonald[t1] = 1;
    graph[macDummy].push_back({t1, 0});
    graph[t1].push_back({macDummy, 0});
  }
  cin >> starNum >> starLimit;
  for (int i = 0; i < starNum; i++) {
    int t1;
    cin >> t1;
    starbucks[t1] = 1;
    graph[starDummy].push_back({t1, 0});
    graph[t1].push_back({starDummy, 0});
  }
  vector<int> macDis = dijkstra(macDummy);
  vector<int> starDis = dijkstra(starDummy);
  int ans = INF;
  for(int i = 1; i <= n; i++) {
    if(macdonald[i] != 1 && starbucks[i] != 1 && macDis[i] <= macLimit && starDis[i] <= starLimit) {
      ans = min(ans, macDis[i] + starDis[i]);
    }
  }
  if(ans == INF) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
}




