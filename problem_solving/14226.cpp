//
// Created by 강호  이 on 2018. 3. 21..
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

const int MAX_RANGE = 2001;
int s;
int visited[MAX_RANGE][MAX_RANGE];

int isRange(int emo) {
  if(emo < 0 || emo > MAX_RANGE) {
    return false;
  }
  return true;
}

int main() {
  int s;
  int ans = INF;
  for(int i = 0; i < MAX_RANGE; i++) {
    for(int j = 0; j < MAX_RANGE; j++) {
      visited[i][j] = INF;
    }
  }
  queue<pair<int, int > > q;
  cin >> s;
  q.push({1, 0});
  visited[1][0] = 0;
  while(!q.empty()) {
    int here = q.front().first;
    int clipboard = q.front().second;
    int dis = visited[here][clipboard];
    int next = visited[here][clipboard] + 1;
    q.pop();
    if(here == s) {
      cout << dis << endl;
      break;
    }
    int paste = here + clipboard;
    if(isRange(paste) && isRange(clipboard) && visited[paste][clipboard] > next) {
      visited[paste][clipboard] = next;
      q.push({paste, clipboard});
    }
    int remove = here - 1;
    if(isRange(remove) && isRange(clipboard) && visited[remove][clipboard] > next) {
      visited[remove][clipboard] = next;
      q.push({remove, clipboard});
    }
    int nextClipboard = here;
    if(isRange(here) && isRange(nextClipboard) && visited[here][nextClipboard] > next) {
      visited[here][nextClipboard] = next;
      q.push({here, nextClipboard});
    }
  }
}

