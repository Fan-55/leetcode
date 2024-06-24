#include <vector>
#include <string>

using namespace std;

class Solution1 {
public:
    bool backspaceCompare(string s, string t) {
      vector<char> stack_s;
      vector<char> stack_t;
      for (auto c: s) {
        if (c == '#' && !stack_s.empty()) {
          stack_s.pop_back();
        } else {
          stack_s.push_back(c);
        }
      }
      for (auto c: t) {
        if (c == '#' && !stack_t.empty()) {
          stack_t.pop_back();
        } else {
          stack_t.push_back(c);
        }
      }
      if (stack_s.size() == stack_t.size()) {
        while(!stack_s.empty()) {
          if (stack_s.back() != stack_t.back()) return false;
          stack_s.pop_back();
          stack_t.pop_back();
        }
        return true;
      }
      return false;
    }
};

class Solution2 {
public:
    bool backspaceCompare(string s, string t) {
      int ptr_s = s.length() - 1;
      int ptr_t = t.length() - 1;
      while (true) {
        ptr_s = nextValidChar(s, ptr_s);
        ptr_t = nextValidChar(t, ptr_t);
        if (ptr_s >= 0 && ptr_t >= 0) {
          if (s[ptr_s] != t[ptr_t]) {
            return false;
          }
          ptr_s--;
          ptr_t--;
        } else if (ptr_s >= 0) {
          return false;
        } else if (ptr_t >= 0) {
          return false;
        } else {
          break;
        }
      }
      return true;
    }

    int nextValidChar(const string& str, int index) {
      int countOfBackspaceChar = 0;
      while(index >= 0) {
        if (countOfBackspaceChar == 0 && str[index] != '#') {
          break;
        } else if (str[index] == '#') {
          countOfBackspaceChar++;
        } else {
          countOfBackspaceChar--;
        }
        index--;
      }
      return index;
    }
};
