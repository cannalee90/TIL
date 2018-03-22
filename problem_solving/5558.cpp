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
char mmap[1000][1000];
int mmove[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int isRange(int r, int c) {
  if(r < 0 || c < 0 || r >=n || c >= m) {
    return false;
  }
  return true;
}

int main() {
  int ans = 0;
  queue <pair<int, int > > q;
  cin >> n >> m >> c;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> mmap[i][j];
      if(mmap[i][j] == 'S') {
        mmap[i][j] = '0';
      }
    }
  }
  for(int k = 0; k < c; k++) {
    int dis[1000][1000];
    pair<int, int> target;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(mmap[i][j] - '0' == k) {
          q.push({i, j});
        } else if(mmap[i][j] - '0' == k + 1) {
          target = {i, j};
        }
        dis[i][j] = INF;
      }
    }
    dis[q.front().first][q.front().second] = 0;
    while(q.size()) {
      int r = q.front().first;
      int c = q.front().second;
      int cost = dis[r][c];
      q.pop();
      for(int i = 0; i < 4; i++) {
        int nextR = r + mmove[i][0];
        int nextC = c + mmove[i][1];
        int nextCost = cost + 1;
        if (isRange(nextR, nextC) && mmap[nextR][nextC] != 'X' && dis[nextR][nextC] > nextCost) {
          q.push({nextR, nextC});
          dis[nextR][nextC] = nextCost;
        }
      }
    }
    ans += dis[target.first][target.second];
  }
  cout << ans << endl;
}




