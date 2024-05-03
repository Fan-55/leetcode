#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int prefix_sum = 0;
      int res = 0;
      unordered_map<int, int> prefix_sum_to_count{{0, 1}};
      for (int i = 0; i < nums.size(); i++) {
        prefix_sum += nums[i];
        int diff = prefix_sum - k;
        if (prefix_sum_to_count.contains(diff)) {
          res += prefix_sum_to_count[diff];
        }
        if (!prefix_sum_to_count.contains(prefix_sum)) {
          prefix_sum_to_count.insert({prefix_sum, 1});
        } else {
          prefix_sum_to_count[prefix_sum]++;
        }
      }
      return res;
    }
};
