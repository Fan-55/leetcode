#include <vector>

using namespace std;

class Solution {
public:
   void swap(int pos1, int pos2, vector<int>& nums) {
    int temp = nums[pos1];
    nums[pos1] = nums[pos2];
    nums[pos2] = temp;
   }
    void sortColors(vector<int>& nums) {
      /// Dutch National Flag algorithm
      int zero_pos = 0;
      int two_pos = nums.size() - 1;
      int current_pos = 0;
      while (current_pos < two_pos) {
        if (nums.at(current_pos) == 0) {
          swap(current_pos, zero_pos, nums);
          ++current_pos;
          ++zero_pos;
        } else if (nums.at(current_pos) == 2) {
          swap(current_pos, two_pos, nums);
          --two_pos;
        } else {
          ++current_pos;
        }
      }
    }
};
