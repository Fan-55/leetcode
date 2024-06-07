#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end(), [](int a, int b){
        if (to_string(a) + to_string(b) > to_string(b) + to_string(a)) return true;
        return false;
      });
      string ans;
      for (auto num: nums) {
        ans+= to_string(num);
      }
      if (ans[0] == '0') return "0";
      return ans;
    }
};
