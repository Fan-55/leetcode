#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      unordered_map<int ,int> prefix_sum_to_first_encountered_position = {{0, -1}};
      int prefix_sum = 0;
      int max_length = 0;
      for (int i = 0; i < nums.size(); i++){
        if (nums[i] == 1) {
          prefix_sum++;
        } else {
          prefix_sum--;
        }
        if (!prefix_sum_to_first_encountered_position.contains(prefix_sum)) {
          prefix_sum_to_first_encountered_position.insert({prefix_sum, i});
        } else {
          max_length = max(i - prefix_sum_to_first_encountered_position[prefix_sum], max_length);
        }
      }
      return max_length;
    }
};