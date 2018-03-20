//
// Created by 강호  이 on 2018. 3. 19..
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

int mmove[2] = {1, -1};
int s, e;

bool isRange(int c) {
  if (c > 100005 || c < 0) return false;
  return true;
}

int main() {
  int ans = 0;
  int dis = 0;
  queue<int> q;
  cin >> s >> e;
  vector<int> visited(100002, INF);

  q.push(s);
  visited[s] = dis;
  if(s == e) {
    cout << '0' << endl;
    cout << '1' << endl;
    exit(1);
  }
  while (q.size()) {
    dis++;
    int length = q.size();
    for(int k = 0; k < length; k++) {
      int c = q.front();
      q.pop();
      for(int i = 0; i < 2; i++) {
        int nextC = c + mmove[i];
        if(isRange(nextC) && visited[nextC] >= dis) {
          visited[nextC] = dis;
          q.push(nextC);
          if(nextC == e) {
            ans ++;
          }

        }
      }

      int nextC = c * 2;
      if (isRange(nextC) && visited[nextC] >= dis) {
        visited[nextC] = dis;
        q.push(nextC);
        if(nextC == e) {
          ans ++;
        }

      }

    }
    if(ans) {
      break;
    }

  }
}
