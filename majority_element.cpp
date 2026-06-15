#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int candidate = nums.at(0);
    int count = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (candidate == nums.at(i)) {
        count++;
      } else if (count == 0) {
        candidate = nums.at(i);
        count++;
      } else if (count > 0) {
        count--;
      }
    }
    return candidate;
  }
};
