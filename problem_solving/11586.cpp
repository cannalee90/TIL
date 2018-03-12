//
// Created by 강호  이 on 2018. 3. 12..
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int n, r;
  cin >> n;
  vector<string> data(n);
  for(int i = 0; i < n; i++) {
    cin >> data[i];
  }
  cin >> r;
  if(r == 1) {
    for(int i = 0; i < n; i++) {
      cout << data[i] << endl;
    }
  } else if(r == 3) {
    for(int i = n - 1; i >= 0; i--) {
      cout << data[i] << endl;
    }
  } else if(r == 2) {
    for(int i = 0; i < n; i++) {
      reverse(data[i].begin(), data[i].end());
      cout << data[i] << endl;
    }
  }
}




