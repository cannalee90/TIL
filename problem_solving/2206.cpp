//
// Created by 강호  이 on 2018. 3. 13..
//


#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <tuple>

using namespace std;

int mmove[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
char mmap[1100][1100];
int dis[2][1100][1100];

int main() {
  int n, m;
  queue <tuple<int, int, int> > q;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> mmap[i][j];
      dis[0][i][j] = 987654321;
      dis[1][i][j] = 987654321;
    }
  }
  q.push(make_tuple(0,0,0));
  dis[0][0][0] = 1;
  while(q.size()) {

    auto cur = q.front();
    int r = get<0>(cur);
    int c = get<1>(cur);
    int d = get<2>(cur);

    q.pop();

    for(int i = 0; i < 4; i++) {
      int nextR = r + mmove[i][0];
      int nextC = c + mmove[i][1];
      if (nextR >= n || nextR < 0 || nextC >= m || nextC < 0) continue;

      if(dis[d][r][c] + 1 < dis[d][nextR][nextC] && mmap[nextR][nextC] == '0') {
        q.push({nextR, nextC, d});
        dis[d][nextR][nextC] = dis[d][r][c] + 1;
      }

      if(mmap[nextR][nextC] == '1' && d == 0 && dis[d + 1][nextR][nextC]  > dis[d][r][c] + 1) {
        q.push({nextR, nextC, d + 1});
        dis[d + 1][nextR][nextC] = dis[d][r][c] + 1;
      }
    }
  }
  int ans = min(dis[0][n - 1][m - 1], dis[1][n - 1][m - 1]);
  if(ans == 987654321) {
    cout << "-1" << endl;
  } else {
    cout << ans  << endl;
  }
}




