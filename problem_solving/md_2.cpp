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
map<string, int> nameCount;

//a:97 z:122
//0:48 9:57


string changeToLower(string str) {
  string ret;
  for(int i = 0; i < str.size(); i++) {
    char cur = str[i];
    if(cur == '@') {
      ret += cur;
    } else if(cur == '-') {
      continue;
    } else {
      ret += tolower(cur);
    }
  }
  return ret;
}

int main() {
  string company;
  string text;
  vector<string > v1;
  cin >> company;
  cin.ignore();
  getline(cin, text);
  stringstream ss(text);
  while(ss.good()) {
    string substr;
    string str;
    getline(ss, substr, ',' );
    stringstream s2(substr);
    vector<string> v2;
    while(s2 >> str) {
      v2.push_back(str);
    }
    if(v2.size()) {
      string first = v2.back();
      string last = v2.front();
      string firstNaming = first + last.front();
      string lastNaming = company + ".com";
      firstNaming = changeToLower(firstNaming);
      lastNaming = changeToLower(lastNaming);
      int cnt = nameCount[firstNaming];
      if(cnt == 0) {
        nameCount[firstNaming] = 2;
      } else {
        nameCount[firstNaming]++;
      }
      if(cnt != 0) {
        cout << firstNaming + to_string(cnt) + "@" + lastNaming << endl;
      } else {
        cout << firstNaming + "@" + lastNaming << endl;
      }

    }
  }
}

