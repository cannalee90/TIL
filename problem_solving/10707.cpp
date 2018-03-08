//
// Created by  이강호 on 2018. 3. 9..
//

#include <iostream>

using namespace std;

int main() {
  int a, b, c, d, p;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
  int xPrice = a * p;
  int yPrice = (p > c ? ((p - c) * d) + b : b);
  if (xPrice > yPrice) {
    cout << yPrice << endl;
  } else {
    cout << xPrice << endl;
  }
}

// simple implementation