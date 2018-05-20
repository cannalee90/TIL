//
// Created by 강호  이 on 2018. 5. 12..
//


#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

#define INF 987654321
int n, m, c;
//a:97 z:122
//0:48 9:57


bool isLowerAndNumber(string str) {
  for(int i = 0; i < str.size(); i++) {
    int num = (int)str[i];
    bool isFalse = false;
    if(!((num >= 'a' && num <= 'z') || (num >= '0' && num <= '9'))) {
      isFalse = true;
    }
    if(isFalse) {
      return false;
    }
  }
  return true;
}

bool hasLowerAndNumber(string str) {
  bool hasLower = false;
  bool hasNumber = false;
  for(int i = 0; i < str.size(); i++) {
    int num = (int)str[i];
    if(num >= 'a' && num <= 'z') {
      hasLower = true;
    }
    if(num >= '0' && num <= '9') {
      hasNumber = true;
    }
  }
  return hasNumber && hasLower;
}

bool hasThreeInRow(string str) {
  for(int i = 2; i < str.size() - 3; i++) {
    int num1 = (int)str[i];
    int num2 = (int)str[i - 1];
    int num3 = (int)str[i - 2];
    if(num1 == num2 && num1 == num3 && num2 == num3) {
      return false;
    }
  }
  return true;
}

int main() {
  string id, pwd;
  bool isValidId = true, isValidPwd = true;
  cin >> id;
  cin >> pwd;
  isValidId = isLowerAndNumber(id) && isValidId;
  isValidId = hasLowerAndNumber(id) && isValidId;
  isValidId = hasThreeInRow(id) && isValidId;
  isValidPwd = isLowerAndNumber(pwd) && isValidPwd;
  isValidPwd = hasLowerAndNumber(pwd) && isValidPwd;
  isValidPwd = hasThreeInRow(pwd) && isValidPwd;
  if(isValidId && isValidPwd) {
    cout << "T" << endl;
  } else {
    cout << "F" << endl;
  }
}

