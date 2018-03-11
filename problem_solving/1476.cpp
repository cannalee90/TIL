//
// Created by  이강호 on 2018. 3. 11..
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int er = 1, sr = 1, mr = 1;
  int e, s, m;
  int emax = 15, smax = 28, mmax = 19;

  cin >> e >> s >> m;
  for(int i = 1; ; i++) {
    if(er > emax) er %= emax;
    if(sr > smax) sr %= smax;
    if(mr > mmax) mr %= mmax;
    if(er == e && sr == s && mr == m) {
      cout << i << endl;
      break;
    } else {
      er++;
      sr++;
      mr++;
    }
  }
}


