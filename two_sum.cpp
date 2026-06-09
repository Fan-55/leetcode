#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_to_index_map;
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums.at(i);
      if (num_to_index_map.contains(diff)) {
        return {i, num_to_index_map.at(diff)};
      }
      num_to_index_map.insert({nums.at(i), i});
    }
    return {};
  }
};

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  Solution solution;
  vector<int> result = solution.twoSum(nums, target);
  std::cout << "===1st test===" << std::endl;
  for (auto index: result) {
    std::cout << "index: " << index << std::endl;
  }
  std::cout << "expected result: [0, 1]" << std::endl;
  nums = {3,2,4};
  target = 6;
  result = solution.twoSum(nums, target);
  std::cout << "===2nd test===" << std::endl;
  for (auto index: result) {
    std::cout << "index: " << index << std::endl;
  }
  std::cout << "expected result: [1, 2]" << std::endl;
  nums = {3,3};
  target = 6;
  result = solution.twoSum(nums, target);
  std::cout << "===3rd test===" << std::endl;
  for (auto index: result) {
    std::cout << "index: " << index << std::endl;
  }
  std::cout << "expected result: [0, 1]" << std::endl;
}