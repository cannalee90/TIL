// two pointer를 이용한 풀이 시간복잡도는 n^2이다.
// 중복처리를 하는것이 힘들어서 완전 개삽질함.. ㅜㅜ


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size() < 3) {
            return ans;
        }
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(sum == 0 && left < right) {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});                    
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left ++;
                    right --;

                } else if(sum < 0) {
                    left++;
                } else if(sum > 0) {
                    right--;
                }
            }
        }
        return ans;
    }
};