//
// Created by 강호  이 on 2018. 3. 27..

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
vector<string> mmap;
int dis[1001][1001];
int mmove[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
map<pair<int, int>, int > exits;
map<pair<int, int>, int > fires;

bool isRange(int r, int c) {
  if(r >= n || r < 0 || c >= m || c < 0) {
    return false;
  }
  return true;
}

bool isPlace(int r, int c) {
  if(mmap[r][c] == '.') {
    return true;
  }
  return false;
}

int bfs(char start) {
  queue<pair<int, int > > q;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dis[i][j] = INF;
      if(mmap[i][j] == start) {
        if(mmap[i][j] == 'J') {
          mmap[i][j] = '.';
        }
        q.push({i, j});
        dis[i][j] = 0;
      }
    }
  }

  bool isPossible = false;
  while(q.size()) {
    int r = q.front().first;
    int c = q.front().second;
    int cost = dis[r][c];
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nextR = mmove[i][0] + r;
      int nextC = mmove[i][1] + c;
      int nextCost = cost + 1;
      if(!isRange(nextR, nextC) && start == 'J') {
        exits[{r,c}] = cost;
      } else if (!isRange(nextR, nextC) && start == 'F') {
        fires[{r,c}] = cost;
      } else if(isPlace(nextR, nextC) && isRange(nextR, nextC) && dis[nextR][nextC] > nextCost){
        dis[nextR][nextC] = nextCost;
        q.push({nextR, nextC});
      }
    }
  }
  return INF;
}

int main() {
  int t = 1;
  std::ios_base::sync_with_stdio(false);
//  cin >> t;
  while(t--) {
    int ans = INF;

    cin >> n >> m;
    fires.clear();
    exits.clear();
    mmap.clear();
    mmap.resize(n);
    for(int i = 0; i < n; i++) {
      cin >> mmap[i];
    }
    int a = bfs('J');
    int b = bfs('F');

    for(auto it = exits.begin(); it != exits.end(); it++) {
      if (fires.size() == 0 || it->second < fires[it->first]) {
        ans = min(ans, it->second);
      }
    }
    if (ans == INF) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << ans + 1 << endl;
    }
  }
}
