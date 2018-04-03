//
// Created by 강호  이 on 2018. 4. 3..
//

class Solution {
public:
  string addBinary(string a, string b) {
    if(b.size() > a.size()) {
      swap(a, b);
    }
    int sum = 0;
    auto it = b.rbegin();
    string ans;
    string nonLeadingZero;
    bool isLeadingZero = true;
    for(auto itor = a.rbegin(); itor != a.rend(); itor++) {
      if(it == b.rend()) {
      }
      if (it != b.rend()) {
        sum += (*itor - '0') + (*it - '0');
        it++;
      } else if(it == b.rend()) {
        sum += (*itor - '0');
      }

      ans += (sum % 2) + '0';
      sum /= 2;
    }
    if(sum != 0) {
      ans += sum + '0';
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
      if(ans[i] == '1') {
        isLeadingZero = false;
      }
      if(!isLeadingZero) {
        nonLeadingZero += ans[i];
      }
    }
    if(nonLeadingZero.size() == 0) {
      return "0";
    } else {
      return nonLeadingZero;
    }
  }
};