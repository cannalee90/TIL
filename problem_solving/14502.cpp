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

int mmap[10][10];
int spread[10][10];
int n, m;
int ans = -INF;
int mmove[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int isRange(int r, int c) {
  if (r >= n || c >= m || r < 0 || c < 0) return false;
  return true;
}

int getAns() {
  queue<pair<int, int> > q;
  int ret = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      spread[i][j] = mmap[i][j];
      if(spread[i][j] == 2) {
        q.push({i, j});
      }
    }
  }

  while(!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;

    q.pop();
    for(int i = 0; i < 4; i++) {
      int nextR = r + mmove[i][0];
      int nextC = c + mmove[i][1];
      if(spread[nextR][nextC] == 0 && isRange(nextR, nextC)) {
        spread[nextR][nextC] = 2;
        q.push({nextR, nextC});
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(spread[i][j] == 0) {
        ret++;
      }
    }
  }

  return ret;
}

void block(int blockCnt) {
  if (blockCnt == 3) {
    ans = max(ans, getAns());
    return;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(mmap[i][j] != 0) continue;
      mmap[i][j] = 1;
      block(blockCnt + 1);
      mmap[i][j] = 0;
    }
  }
}

int main() {
  int safe = 0;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> mmap[i][j];
    }
  }

  block(0);

  cout << ans << endl;
}




