#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
      vector<string> stack;
      for (char c:s) {
        if (c != ']') {
          stack.push_back(string(1, c));
        } else {
          /// 1. find str in brackets
          string str_in_brackets;
          while(stack.back() != "[") {
            str_in_brackets = stack.back() + str_in_brackets;
            stack.pop_back();
          }
          /// 2. pop open bracket
          stack.pop_back();

          /// 3. find k
          int digit_count = 0;
          int repeated_count = 0;
          while(!stack.empty() && stack.back().c_str()[0] >= '0' &&  stack.back().c_str()[0] <= '9') {
            repeated_count = (stack.back().c_str()[0] - '0') * pow(10, digit_count) + repeated_count;
            digit_count++;
            stack.pop_back();
          }

          /// 4. decode
          string repeated_str;
          for (int i = 0; i < repeated_count; i++) {
            repeated_str += str_in_brackets;
          }
          /// 5. put back to stack
          stack.push_back(repeated_str);
        }
      }
      string result;
      for (const string& str: stack) {
        result += str;
      }
      return result;
    }
};
