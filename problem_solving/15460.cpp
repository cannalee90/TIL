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
char mmap[1000][1000];
int mmove[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
  int n;
  int minValue = INF;
  double mmaxValue = -INF;
  vector<int> arr;
  vector<int> psum;
  vector<int> mmin;
  vector<int> ans;
  cin >> n;
  arr.resize(n);
  psum.resize(n);
  mmin.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  psum[n - 1] = arr[n - 1];
  for(int i = n - 2; i >= 0; i--) {
    psum[i] = psum[i + 1] + arr[i];
  }
  for(int i = n - 1; i >= 0; i--) {
    minValue = min(minValue, arr[i]);
    mmin[i] = minValue;
  }
  for(int i = 1; i < n - 1; i++) {
    int factor = n - i;
    int num = psum[i];
    double nnum = (double)num / (factor);
    if(mmaxValue < nnum) {
      ans.clear();
      ans.push_back(i);
      mmaxValue = nnum;
    } else if(mmaxValue == nnum) {
      ans.push_back(i);
    }

  }
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}




