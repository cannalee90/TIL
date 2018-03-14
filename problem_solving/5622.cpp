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

// 1
// 2 ABC
// 3 DEF
// 4 GHI
// 5 JKL
// 6 MNO
// 7 PQRS
// 8 TUV
// 9 WXYZ
// 0

int main() {
  string str;
  int ans = 0;
  cin >> str;
  for(int i = 0; i < str.size(); i++) {
    char cur = str[i];
    if(cur >= 'A' && cur <= 'C') {
      ans += 2;
    } else if(cur >= 'D' && cur <= 'F') {
      ans += 3;
    } else if(cur >= 'G' && cur <= 'I') {
      ans += 4;
    } else if(cur >= 'J' && cur <= 'L') {
      ans += 5;
    } else if(cur >= 'M' && cur <= 'O') {
      ans += 6;
    } else if(cur >= 'P' && cur <= 'S') {
      ans += 7;
    } else if(cur >= 'T' && cur <= 'V') {
      ans += 8;
    } else if(cur >= 'W' && cur <= 'Z') {
      ans += 9;
    }
    ans ++;
  }
  cout << ans << endl;
}




