#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char, int> letter_to_count_map;
      int ans = 0;
      bool has_odd_item = false;
      for(int i = 0; i < s.length(); i++) {
        letter_to_count_map[s[i]]++;
      }
      for (auto entry: letter_to_count_map) {
        int count = entry.second;
        if (count % 2 == 0) {
          ans += count;
        } else if (count % 2 == 1 && count > 1) {
          ans += (count - 1);
          has_odd_item = true;
        } else {
          has_odd_item = true;
        }
      }
      if (has_odd_item) {
        ans +=1;
      }
      return ans;
    }
};