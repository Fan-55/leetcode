#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> res;
      for (int i = 0; i < nums.size(); i++) {
        int left = i + 1;
        int right = nums.size() - 1;
        if (i > 0 && nums[i] == nums[i - 1]) {
          continue;
        }
        while (left < right) {
          if (nums[i] + nums[left] + nums[right] > 0) {
            right--;
          } else if (nums[i] + nums[left] + nums[right] < 0) {
            left++;
          } else {
            res.push_back({nums[i], nums[left], nums[right]});
            left++;
            while (nums[left] == nums[left - 1] && left < right) {
              left++;
            }
          }
        }
      }
      return res;
    }
};
