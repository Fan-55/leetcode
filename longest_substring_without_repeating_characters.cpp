#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char> char_set;
      int ans = 0;
      int l = 0;
      int r = 0;
      while (r < s.length()) {
        if (!char_set.contains(s[r])) {
          char_set.insert(s[r]);
          r++;
          ans = max(ans,r-l);
        } else {
          char_set.erase(s[l]);
          l++;
        }
      }
      return ans;
    }
};
