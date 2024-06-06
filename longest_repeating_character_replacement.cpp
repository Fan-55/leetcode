#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int characterReplacement(string s, int k) {
      unordered_map<char,int> substr_char_to_count_mp;
      int ans = 0;
      int r = 0;
      int l = 0;
      while (r < s.length()) {
        substr_char_to_count_mp[s[r]]++;
        if ((r - l + 1) - primaryCharCount(substr_char_to_count_mp) > k) {
          substr_char_to_count_mp[s[l]]--;
          l++;
        }
        ans = max(ans, r - l + 1);
        r++;
      }
      return ans;
    }

    int primaryCharCount(unordered_map<char,int> mp) {
      int max = 0;
      for (auto pair:mp) {
        if (pair.second > max) {
          max = pair.second;
        }
      }
      return max;
    }
};

class Solution2 {
public:
    int characterReplacement(string s, int k) {
      unordered_map<char,int> substr_char_to_count_mp;
      int ans = 0;
      int r = 0;
      int l = 0;
      int max_count = 0;
      while (r < s.length()) {
        substr_char_to_count_mp[s[r]]++;
        max_count = max(max_count, substr_char_to_count_mp[s[r]]);
        if ((r - l + 1) - max_count > k) {
          substr_char_to_count_mp[s[l]]--;
          l++;
        }
        ans = max(ans, r - l + 1);
        r++;
      }
      return ans;
    }
};
