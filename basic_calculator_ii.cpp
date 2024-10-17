#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
      vector<int> num_stack;
      vector<int> operator_stack;
      int i = 0;
      while (i < s.size()) {
        int current_num = 0;
        while(s[i] == ' ') {
          i++;
        }
        while(isDigit(s[i])) {
          current_num = current_num * 10 + (s[i] - '0');
          i++;
        }
        while(s[i] == ' ') {
          i++;
        }
        if (!operator_stack.empty() && isMulOrDiv(operator_stack.back())) {
          int new_num = 0;
          if (operator_stack.back() == '*') {
            new_num = num_stack.back() * current_num;
          } else {
            new_num = num_stack.back() / current_num;
          }
          num_stack.pop_back();
          num_stack.push_back(new_num);
          operator_stack.pop_back();
        } else {
          num_stack.push_back(current_num);
        }
        if (isOperator(s[i])) {
          operator_stack.push_back(s[i]);
        }
        i++;
      }
      int sum = num_stack.front();
      num_stack.erase(num_stack.begin());
      while(!num_stack.empty()) {
        int operandRight = num_stack.back();
        num_stack.pop_back();
        if (operator_stack.back() == '+') {
          sum += operandRight;
        } else {
          sum -= operandRight;
        }
        operator_stack.pop_back();
      }
      return sum;
    }

    bool isDigit(char c) {
      return c - '0' >= 0 && c - '0' <= 9;
    }

    bool isMulOrDiv(char c) {
      return c == '*' || c == '/';
    }

    bool isOperator(char c) {
      return c == '*' || c == '/' || c == '+' || c == '-';
    }
};
