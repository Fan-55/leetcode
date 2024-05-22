#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int result = nums[0] + nums[1] + nums[nums.size() - 1];
      for (int i = 0; i < nums.size() - 2; i++) {
        int l = i + 1;
        int r = nums.size() - 1;
        int current_sum = nums[i] + nums[l] + nums[r];
        while (l < r) {
          current_sum = nums[i] + nums[l] + nums[r];
          if (current_sum > target) {
            r--;
          } else if (current_sum < target) {
            l++;
          } else {
            break;
          }
        }
        if (abs(current_sum - target) < abs(result - target)) {
          result = current_sum;
        }
      }
      return result;
    }
};