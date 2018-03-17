//
// Created by 강호  이 on 2018. 3. 17..
//

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <tuple>

using namespace std;

#define INF 987654321

int n = 6;
int m = 12;
int mmove[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<string> mmap(n);

int isRange(int r, int c) {
  if (r >= n || c >= m || r < 0 || c < 0) return false;
  return true;
}

int markPuyo(int r, int c) {
  vector<string> backup;
  queue<pair<int, int> > q;
  char puyo = mmap[r][c];
  int cnt = 1;

  q.push({r, c});
  for(int i = 0; i < n; i++) {
    backup.push_back(mmap[i]);
  }

  backup[r][c] = '*';

  while(!q.empty()) {
    int initR = q.front().first;
    int initC = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nextR = initR + mmove[i][0];
      int nextC = initC + mmove[i][1];
      if(isRange(nextR, nextC) && backup[nextR][nextC] == puyo) {
        backup[nextR][nextC] = '*';
        cnt++;
        q.push({nextR, nextC});
      }
    }
  }

  if(cnt >= 4) {
    mmap = backup;
    return true;
  } else {
    return false;
  }
}


int batchPuyo() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(mmap[i][j] == '*') {
        mmap[i].erase(mmap[i].begin() + j);
        mmap[i].insert(mmap[i].begin(), '.');
      }
    }
  }
}

int main() {
  vector<string> tmp(13);
  for(int i = 0; i < m; i++) {
    cin >> tmp[i];
  }

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      mmap[j].push_back(tmp[i][j]);
    }
  }
  int ans = 0;

  while(1) {
    int flag = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if (mmap[i][j] != '.' && mmap[i][j] != '*') {
          if (markPuyo(i, j)) {
            flag++;
          }
        }
      }
    }

    if(!flag) {
      break;
    }
    else {
      ans ++;
      batchPuyo();
    }
  }
  cout << ans << endl;
}