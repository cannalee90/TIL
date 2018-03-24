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
int data[100][3];
int ans = 0;

int isValid(string score) {
  int tmp[3];
  if(score[0] == score[1] || score[0] == score[2] || score[1] == score[2]) return 0;
  for(int i = 0; i < n; i++) {
    tmp[0] = data[i][0] / 100;
    tmp[1] = (data[i][0] % 100) / 10;
    tmp[2] = (data[i][0] % 100) % 10;

    int strike = 0;
    int ball = 0;
    for(int j = 0; j < score.size(); j++) {
      if (tmp[j] == score[j] - '0') {
        strike ++;
      }
    }
    for(int j = 0; j < score.size(); j++) {
      for(int k = 0; k < score.size(); k++) {
        if(score[j] - '0' == tmp[k] && j != k) {
          ball ++;
        }
      }
    }
//    cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << " " << score << " " << strike << " " << ball << endl;
    if (strike != data[i][1] || ball != data[i][2]) {
      return 0;
    }
  }
//  cout << score << endl;
  return 1;
}

void bruteForce(string score, int length) {
  if (length == 3) {
    ans += isValid(score);
    return;
  }
  for(int i = 1; i <= 9; i++) {
    score += '0' + i;
    bruteForce(score, length + 1);
    score.pop_back();
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n ; i++) {
    cin >> data[i][0] >> data[i][1] >> data[i][2];
  }
  bruteForce("", 0);
  cout << ans << endl;
}




