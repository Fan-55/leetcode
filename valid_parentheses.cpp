#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
      unordered_map<char, char> close_to_open = {{'}', '{'}, {')', '('}, {']', '['}};
      vector<char> stack;
      for (int i = 0; i < s.length(); i++) {
        /// find close bracket
        if (close_to_open.count(s[i])) {
          /// brackets match
          if (!stack.empty() && stack.back() == close_to_open[s[i]]) {
            stack.pop_back();
          } else {
            return false;
          }
        } else { /// find open bracket
          stack.push_back(s[i]);
        }
      }
      return stack.empty();
    }
};
