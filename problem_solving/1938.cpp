//
// Created by 강호  이 on 2018. 3. 14..
//


#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <tuple>

using namespace std;

#define INF 987654321

char mmap[60][60];
int dis[2][60][60];
int n, bRotate, eRotate;
int mmove[8][2] = {{0,1},{1,0},{0,-1},{-1, 0},{1,1},{1,-1},{-1,1},{-1,-1}};

pair<int, int> makePin(char target) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(mmap[i][j] == target) {
        if(mmap[i + 1][j] == target) {
          if(target == 'B') {
            bRotate = 0;
          }
          if(target == 'E') {
            eRotate = 0;
          }
          return {i + 1, j};
        } else if(mmap[i][j + 1] == target) {
          if(target == 'B') {
            bRotate = 1;
          }
          if(target == 'E') {
            eRotate = 1;
          }
          return {i, j + 1};
        }
      }
    }
  }
}
// 90 == 0
// 180 == 1

bool isRange(pair<int, int> coor) {
  int r = coor.first;
  int c = coor.second;
  if(r < 0 || c < 0 || r >= n || c >= n) {
    return false;
  }
  return true;
}

bool isRotatable(int rotate, pair<int, int> coor) {
  int r = coor.first;
  int c = coor.second;
  for(int i = 0 ; i < 8; i++) {
    int nextR = r + mmove[i][0];
    int nextC = c + mmove[i][1];
    if(!isRange({nextR, nextC}) || mmap[nextR][nextC] == '1') {
      return false;
    }
  }
  return true;
}

bool isUp(int rotate, pair<int, int> coor) {
  int r = coor.first;
  int c = coor.second;
  if(rotate == 0 && isRange({r - 2, c}) && mmap[r - 2][c] != '1' && mmap[r - 1][c] != '1') {
    return true;
  }
  if(rotate == 1 && isRange({r - 1, c}) && mmap[r - 1][c] != '1' && mmap[r - 1][c - 1] != '1' && mmap[r - 1][c + 1] != '1') {
    return true;
  }
  return false;
}

bool isDown(int rotate, pair<int, int> coor) {
  int r = coor.first;
  int c = coor.second;
  if(rotate == 0 && isRange({r + 2, c}) && mmap[r + 2][c] != '1' && mmap[r + 1][c] != '1') {
    return true;
  }
  if(rotate == 1 && isRange({r + 1, c}) && mmap[r + 1][c + 1] != '1' && mmap[r + 1][c - 1] != '1' && mmap[r + 1][c] != '1') {
    return true;
  }
  return false;
}

bool isRight(int rotate, pair<int, int> coor) {
  int r = coor.first;
  int c = coor.second;
  if(rotate == 0 && isRange({r, c + 1}) && mmap[r][c + 1] != '1' && mmap[r + 1][c + 1] != '1' && mmap[r - 1][c + 1] != '1') {
    return true;
  }
  if(rotate == 1 && isRange({r, c + 2}) && mmap[r][c + 2] != '1' && mmap[r][c + 1] != '1') {
    return true;
  }
  return false;
}

bool isLeft(int rotate, pair<int, int> coor) {
  int r = coor.first;
  int c = coor.second;
  if(rotate == 0 && isRange({r, c - 1}) && mmap[r][c - 1] != '1' && mmap[r + 1][c - 1] != '1' && mmap[r - 1][c - 1] != '1') {
    return true;
  }
  if(rotate == 1 && isRange({r, c - 2}) && mmap[r][c - 2] != '1' && mmap[r][c - 1] != '1') {
    return true;
  }
  return false;
}

int dfs(int rotate, pair<int, int> coor) {
  int r = coor.first;
  int c = coor.second;
  int cur = dis[rotate][r][c];

  if(isUp(rotate, coor) && dis[rotate][r - 1][c] > cur + 1) {
    dis[rotate][r - 1][c] = cur + 1;
    dfs(rotate, {r - 1, c});
  }
  // D
  if(isDown(rotate, coor) && dis[rotate][r + 1][c] > cur + 1) {
    dis[rotate][r + 1][c] = cur + 1;
    dfs(rotate, {r + 1, c});
  }
  // L
  if(isLeft(rotate, coor) && dis[rotate][r][c - 1] > cur + 1) {
    dis[rotate][r][c - 1] = cur + 1;
    dfs(rotate, {r, c - 1});
  }
  // R
  if(isRight(rotate, coor) && dis[rotate][r][c + 1] > cur + 1) {
    dis[rotate][r][c + 1] = cur + 1;
    dfs(rotate, {r, c + 1});
  }
  // T
  if(isRotatable(rotate, coor) && dis[(rotate + 1) % 2][r][c] > cur + 1) {
    dis[(rotate + 1) % 2][r][c] = cur + 1;
    dfs((rotate + 1) % 2, {r, c});
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> mmap[i][j];
      dis[0][i][j] = INF;
      dis[1][i][j] = INF;
    }
  }

  pair<int, int> ePoint = makePin('E');
  pair<int, int> bPoint = makePin('B');

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(mmap[i][j] == 'E' || mmap[i][j] == 'B') {
        mmap[i][j] = '0';
      }
    }
  }

  dis[bRotate][bPoint.first][bPoint.second] = 0;
  dfs(bRotate, bPoint);

  if(dis[eRotate][ePoint.first][ePoint.second] != 987654321) {
    cout << dis[eRotate][ePoint.first][ePoint.second] << endl;
  } else {
    cout << '0' << endl;
  }
}




