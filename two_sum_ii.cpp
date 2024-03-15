#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int left = 0;
      int right = numbers.size() - 1;
      vector<int> res;
      /// It's guarantee to have solution so the condition of stopping the loop doesn't matter
      while(left < right) {
        if (numbers[left] + numbers[right] > target) {
          right--;
        } else if (numbers[left] + numbers[right] < target) {
          left++;
        } else {
          res.push_back(left+1);
          res.push_back(right+1);
          break;
        }
      }
      return res;
    }
};