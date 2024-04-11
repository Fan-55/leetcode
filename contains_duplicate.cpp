#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
      unordered_set<int> hash_set{};
      for (int num: nums) {
        if (hash_set.count(num) > 0) {
          return true;
        }
        hash_set.insert(num);
      }
      return false;
    }
};