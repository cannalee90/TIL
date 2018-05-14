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
int mmap[200][200] = {{0}};
int mmove[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int visted[200][200] = {{0}};
int cnt = 2;
vector<pair<int, int> > range;

void fill(int startX, int endX, int startY, int endY) {
  for(int i = startX; i <= endX; i++) {
    mmap[i][startY] = 1;
    mmap[i][endY] = 1;
  }
  for(int i = startY; i <= endY; i++) {
    mmap[startX][i] = 1;
    mmap[endX][i] = 1;
  }
}

bool isRange(int x, int y) {
  if(x < 0 || y < 0 || x > 100 || y > 100) {
    return false;
  }
  for(int i = 0; i < range.size() / 2; i++) {
    int x1 = range[i * 2].first;
    int y1 = range[i * 2].second;
    int x2 = range[i * 2 + 1].first;
    int y2 = range[i * 2 + 1].second;
    if(x > x1 && x < x2 && y > y1 && y < y2) {
      return true;
    }
  }
  return false;
}

int dfs(int x, int y, int cnt) {
  int ret = 1;
  mmap[x][y] = cnt;
  for (int i = 0; i < 4; i++) {
    int nextX = x + mmove[i][0];
    int nextY = y + mmove[i][1];
    if (isRange(nextX, nextY) && mmap[nextX][nextY] == 0) {
      ret += dfs(nextX, nextY, cnt);
    }
  }
  return ret;
}

void print_mmap() {
  for(int i =0 ; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      cout << mmap[i][j];
    }
    cout << endl;
  }
}

int main() {
  int ans = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    scanf(" %d,%d,%d,%d", &x1, &y1, &x2, &y2);
    int startX = min(x1, x2);
    int endX = max(x1, x2);
    int startY = min(y1, y2);
    int endY = max(y1, y2);
    fill(startX, endX, startY, endY);
    range.push_back({startX, startY});
    range.push_back({endX, endY});
  }
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(mmap[i][j] == 0 && isRange(i,j)) {
        ans =  max(ans, dfs(i, j, cnt));
        cnt++;
      }
    }
  }
  cout << ans << endl;
}

