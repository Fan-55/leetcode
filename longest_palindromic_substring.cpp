#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      string ans;
      int max_len = 0;
      for (int i = 0; i < s.length(); i++) {
        /// odd number center
        int l = i;
        int r = i;
        while(l >= 0 && r <= s.length()-1 && s[l]==s[r]) {
          if (r - l + 1 > max_len) {
            max_len = r - l + 1;
            ans = s.substr(l, max_len);
          }
          l--;
          r++;
        }
        /// even number center
        l = i;
        r = i + 1;
        while(l >= 0 && r <= s.length()-1 && s[l]==s[r]) {
          if (r - l + 1 > max_len) {
            max_len = r - l + 1;
            ans = s.substr(l, max_len);
          }
          l--;
          r++;
        }
      }
      return ans;
    }
};