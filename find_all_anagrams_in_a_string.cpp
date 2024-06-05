#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> ans;
      if (s.length() < p.length()) return ans;
      unordered_map<char,int> char_to_count_p;
      for (int i = 0; i < p.length(); i++) {
        char_to_count_p[p[i]]++;
      }

      unordered_map<char, int> initial_substr_char_to_count;
      for (int i = 0; i < p.length(); i++) {
        initial_substr_char_to_count[s[i]]++;
      }

      unordered_map<char, int> diff_char_to_count;
      for (auto entry: initial_substr_char_to_count) {
        if (!char_to_count_p.count(entry.first)) {
          diff_char_to_count[entry.first] = entry.second;
        } else if (char_to_count_p[entry.first] != entry.second) {
          diff_char_to_count[entry.first] = entry.second - char_to_count_p[entry.first];
        }
      }

      for (auto entry: char_to_count_p) {
        if (!initial_substr_char_to_count.count(entry.first)) {
          diff_char_to_count[entry.first] = -entry.second;
        }
      }

      if (diff_char_to_count.empty()) {
        ans.push_back(0);
      }

      for (int i = 1; i < s.length() - p.length() + 1; i++) {
        diff_char_to_count[s[i-1]]--;
        diff_char_to_count[s[i+p.length()-1]]++;
        if (diff_char_to_count.count(s[i-1]) && diff_char_to_count[s[i-1]] == 0) {
          diff_char_to_count.erase(s[i-1]);
        }
        if (diff_char_to_count.count(s[i+p.length()-1]) && diff_char_to_count[s[i+p.length()-1]] == 0) {
          diff_char_to_count.erase(s[i+p.length()-1]);
        }
        if (diff_char_to_count.empty()) {
          ans.push_back(i);
        }
      }
      return ans;
    }
};

/// Cleaner but performance is worse than Solution1
class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> ans;
      if (s.length() < p.length()) return ans;
      unordered_map<char,int> char_to_count_p;
      for (int i = 0; i < p.length(); i++) {
        char_to_count_p[p[i]]++;
      }
      unordered_map<char, int> s_substr_char_to_count;
      for (int i = 0; i <= s.length(); i++) {
        if (i < p.length()) {
          s_substr_char_to_count[s[i]]++;
        } else {
          if (isAnagram(s_substr_char_to_count, char_to_count_p)) {
            ans.push_back(i - p.length());
          }
          s_substr_char_to_count[s[i - p.length()]]--;
          if (s_substr_char_to_count[s[i - p.length()]] == 0) {
            s_substr_char_to_count.erase(s[i - p.length()]);
          }
          s_substr_char_to_count[s[i]]++;
        }
      }
      return ans;
    }

    bool isAnagram(unordered_map<char, int>ms, unordered_map<char, int>mp) {
      if (ms.size() != mp.size()) return false;
      for (auto pair: mp) {
        if (ms[pair.first] != pair.second) {
          return false;
        }
      }
      return true;
    }
};
