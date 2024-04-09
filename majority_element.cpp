#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
      double target_size = nums.size() / 2.0;
      std::unordered_map<int,int> item_to_count_map;
      for (int i = 0; i < nums.size(); i++) {
        if (item_to_count_map.count(nums[i])) {
          item_to_count_map[nums[i]] += 1;
        } else {
          item_to_count_map[nums[i]] = 1;
        }
        if (item_to_count_map[nums[i]] >= target_size) {
          return nums[i];
        }
      }
      return nums[0];
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
      /// boyer-moore voting algorithm
      int count = 0;
      int candidate = 0; /// can be arbitrary value since value of nums is unknown yet
      for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
          candidate = nums.at(i);
          count = 1;
        } else if ( candidate == nums.at(i)) {
          count++;
        } else {
          count--;
        }
      }
      return candidate;
    }
};
