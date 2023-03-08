#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> result;
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum > target) {
                right = right - 1;
                continue;
            } else if (sum < target) {
                left = left + 1;
                continue;
            } else {
                result.push_back(left+1);
                result.push_back(right+1);
                break;
            }
        }
        return result;
    }
};
