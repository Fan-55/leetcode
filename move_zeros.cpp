#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int index_of_swappable_zero = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums.at(i) != 0) {
        /// swap
        int tmp = nums.at(index_of_swappable_zero);
        nums[index_of_swappable_zero] = nums.at(i);
        nums[i] = tmp;
        index_of_swappable_zero++;
      }
    }
  }
};

int main() {
  vector<int> nums = {0,0,1,0,3};
  Solution s;
  s.moveZeroes(nums);
  cout << "mutated nums: [ ";
  for (int num: nums) {
    cout << num << " ";
  }
  cout << "]" << endl;
}