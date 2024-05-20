#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int l =0;
      int r = nums.size() - 1;
      vector<int> ans(nums.size());

      for(int i = nums.size() - 1; i >= 0; i--) {
        if (nums[l] * nums[l] >= nums[r] * nums[r]) {
          ans[i] = nums[l] * nums[l];
          l++;
        } else {
          ans[i] = nums[r] * nums[r];
          r--;
        }
      }

      return ans;
    }
};