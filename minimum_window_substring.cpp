#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
      if (t.length() > s.length() || t == "") return "";
      unordered_map<char, int> char_to_count_t;
      for (auto c:t) {
        char_to_count_t[c]++;
      }
      int min_window_size = INT_MAX;

      int target_match_count = char_to_count_t.size();
      int match_count = 0;
      int l = 0;
      vector<int> min_window_pos = {-1, -1};
      unordered_map<char, int> char_to_count_s;
      for (int i = 0; i < s.length(); i++) {
        char_to_count_s[s[i]]++;
        /// find match
        if (char_to_count_t.count(s[i]) && char_to_count_t[s[i]] == char_to_count_s[s[i]]) {
          match_count++;
          /// trim the window
          while(match_count == target_match_count) {
            char_to_count_s[s[l]]--;
            if (char_to_count_t.count(s[l]) && char_to_count_s[s[l]] < char_to_count_t[s[l]]) {
              match_count--;
              if (i - l + 1 < min_window_size) {
                min_window_size = i - l + 1;
                min_window_pos[0] = l;
                min_window_pos[1] = i;
              }
            }
            l++;
          }
        }
      }
      if (min_window_size < INT_MAX) {
        return s.substr(min_window_pos[0], min_window_pos[1]-min_window_pos[0] + 1);
      } else {
        return "";
      }
    }
};