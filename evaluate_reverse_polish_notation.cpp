#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      vector<int> stack;
      for(const string& token: tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
          int result = 0;
          int operand_str2 = stack.back();
          stack.pop_back();
          int operand_str1 = stack.back();
          stack.pop_back();
          if (token == "+") {
            result = operand_str1 + operand_str2;
          } else if (token == "-") {
            result = operand_str1 - operand_str2;
          } else if (token == "*") {
            result = operand_str1 * operand_str2;
          } else {
            result = operand_str1/operand_str2;
          }
          stack.push_back(result);
        } else {
          stack.push_back(stoi(token));
        }
      }
      return stack.back();
    }
};
