#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string ans;
      /// for each character
      for (int i = 0; i < strs[0].length(); i++) {
        /// check if the ith character of all the strings is the same
        for (const string& str: strs) {
          if (i >= str.length() || str[i] != strs[0][i]) return ans;
        }
        ans += strs[0][i];
      }
      return ans;
    }
};