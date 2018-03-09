//
// Created by 강호  이 on 2018. 3. 9..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int r, c, zr, zc;
  scanf("%d %d %d %d", &r, &c, &zr, &zc);
  vector<vector<char> > ins(r);
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      char tmp;
      cin >> tmp;
      ins[i].push_back(tmp);
    }
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < zr; j++) {
      for(int k = 0; k < c; k++) {
        for(int l = 0; l < zc; l++) {
          cout << ins[i][k];
        }
      }
      cout << endl;
    }
  }
}
