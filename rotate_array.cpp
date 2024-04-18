#include <vector>

using namespace std;

class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
      int res[nums.size()];
      for (int i = 0; i < nums.size(); i++) {
        res[(i + k) % nums.size()] = nums[i];
      }
      for (int i = 0; i < nums.size(); i++) {
        nums[i] = res[i];
      }
    }
};

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
      /// 0. Avoid useless rotations
      k = k % nums.size();

      /// 1. Reverse entire array
      int l = 0;
      int r = nums.size() - 1;
      while (l < r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r--;
      }

      /// 2. Reverse the first k elements
      l = 0;
      r = k - 1;
      while (l < r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r--;
      }

      /// 3. Reverse the reset elements
      l = k;
      r = nums.size() - 1;
      while (l < r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r--;
      }
    }
};