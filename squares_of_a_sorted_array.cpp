#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int left_pos = 0;
    int right_pos = nums.size() - 1;
    vector<int> ans(nums.size());
    for (int i = ans.size() - 1; i >= 0; i--) {
      if (pow(nums.at(left_pos), 2) > pow(nums.at(right_pos), 2)) {
        ans.at(i) = pow(nums.at(left_pos), 2);
        left_pos++;
      } else {
        ans.at(i) = pow(nums.at(right_pos), 2);
        right_pos--;
      }
    }
    return ans;
  }
};

void test_case (vector<int>& nums) {
  cout << " input array [ ";
  for (int num: nums) {
    cout << num << " ";
  }
  cout << "]" << endl;


  Solution s;
  vector<int> ans = s.sortedSquares(nums);
  cout << " sorted squared array [ ";
  for (int squared_num: ans) {
    cout << squared_num << " ";
  }
  cout << "]" << endl;
}

int main () {
  vector<int> nums = {-4,-1, 0, 3, 10};
  test_case(nums);
  nums = {0};
  test_case(nums);
  return 0;
}