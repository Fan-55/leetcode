#include <string>

using namespace std;

const int max_int = 2147483647;
const int min_int = -2147483648;

class Solution {
public:
    int myAtoi(string s) {
      string magnitude_str;
      if (!s.length()) return 0;
      int l = 0;
      bool is_negative = false;
      /// check whitespace
      while (l < s.length()) {
        if (s[l] == ' ') {
          l++;
        } else {
          break;
        }
      }

      /// check the sign
      if (l < s.length()) {
        if (s[l] == '-') {
          is_negative = true;
          l++;
        } else if (s[l] == '+') {
          l++;
        }
      }

      /// Check leading zeros
      while (l < s.length()) {
        if (is_digit(s[l])) {
          if (s[l] == 0) {
            l++;
          } else {
            break;
          }
        } else {
          return 0;
        }
      }

      /// Get magnitude
      while (l < s.length()) {
        if (!is_digit(s[l])) {
          if (!magnitude_str.length()) {
            return 0;
          }
          break;
        } else {
          magnitude_str += s[l];
          l++;
        }
      }

      /// String to number
      int64_t magnitude_num = 0;
      for (int i = 0; i < magnitude_str.length(); i++) {
        magnitude_num = magnitude_num * 10 + magnitude_str[i] - '0';
        if (magnitude_num > max_int) {
          if (is_negative) {
            return min_int;
          }
          return max_int;
        }
      }

      if (is_negative) {
        magnitude_num *= -1;
      }
      return magnitude_num;
    }

    bool is_digit (char c) {
      return c >= '0' && c <= '9';
    }
};