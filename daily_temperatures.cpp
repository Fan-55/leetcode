#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
      vector<int> stack;
      vector<int> index_stack;
      vector<int> ans(temperatures.size(), 0);
      for (int i = 0; i < temperatures.size(); i++) {
        while (!stack.empty() && temperatures[i] > stack.back()) {
          ans[index_stack.back()] = i - index_stack.back();
          stack.pop_back();
          index_stack.pop_back();
        }
        stack.push_back(temperatures[i]);
        index_stack.push_back(i);
      }
      return ans;
    }
};
