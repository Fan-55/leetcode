#include <string>

const int CAPITAL_A_TO_Z_ASCII_UB = 90;
const int CAPITAL_A_TO_Z_ASCII_LB = 65;

const int CAPITAL_a_TO_z_ASCII_UB = 122;
const int CAPITAL_a_TO_z_ASCII_LB = 97;

const int zero_TO_nine_ASCII_UB = 57;
const int zero_TO_nine_ASCII_LB = 48;

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      int l = 0;
      int r = s.length() - 1;
      while (l < r) {
        while(l < r && !isalnum(s[l])) {
          l++;
        }
        while(l < r && !isalnum(s[r])) {
          r--;
        }
        if (tolower(s[l]) != tolower(s[r])) return false;
        l++;
        r--;
      }
      return true;
    }

    bool isalnum(char c) {
      if ((int)c >= CAPITAL_A_TO_Z_ASCII_LB && (int)c <= CAPITAL_A_TO_Z_ASCII_UB
      || (int) c >= CAPITAL_a_TO_z_ASCII_LB && (int)c <= CAPITAL_a_TO_z_ASCII_UB
      || (int) c >= zero_TO_nine_ASCII_LB && (int) c <= zero_TO_nine_ASCII_UB) {
        return true;
      }
      return false;
    }
};
