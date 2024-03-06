#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> number_to_index_map;
      vector<int> answer;
      for (int index = 0; index < nums.size(); index++) {
        int diff = target - nums[index]; /// diff is the value of another number
        /// if another number is in the map
        if (number_to_index_map.find(diff) != number_to_index_map.end()) {
          answer.push_back(index);
          answer.push_back(number_to_index_map.at(diff));
          break;
        } else { /// insert current number to the map
          number_to_index_map.insert({nums[index], index});
        }
      }
      return answer;
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