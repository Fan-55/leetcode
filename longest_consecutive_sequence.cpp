#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for(int num: nums) {
          nums_set.insert(num);
        }
        int max_length = 0;
        for (int num: nums_set) {
          if (!nums_set.contains(num-1)) {
            int length = 0;
            int current = num;
            while(nums_set.contains(current)) {
              length++;
              current++;
            }
            max_length = max(max_length, length);
          }
        }
        return max_length;
    }
};