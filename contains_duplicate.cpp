#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++) {
      if (set.contains(nums.at(i))) {
        return true;
      }
      set.insert(nums.at(i));
    }
    return false;
  }
};