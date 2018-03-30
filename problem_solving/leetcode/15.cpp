//
// Created by 강호  이 on 2018. 3. 30..
//


class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
    sort(nums.begin(), nums.end());
    if(nums.size() < 3) {
      return ans;
    }
    set<vector<int> > eraseDuplicate;
    for(int i = 0; i < nums.size() - 2; i++) {
      for(int j = i + 1; j < nums.size() - 1; j++) {
        auto num = lower_bound(nums.begin() + j + 1, nums.end(), -(nums[i] + nums[j]));
        if(num != nums.end() && *num == -(nums[i] + nums[j])) {
          eraseDuplicate.insert({nums[i], nums[j], *num});
        }
      }
    }
    for(auto itor = eraseDuplicate.begin(); itor != eraseDuplicate.end(); itor++) {
      ans.push_back(*itor);
    }
    return ans;
  }
};

