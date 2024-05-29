#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    bool isAnagram(string s, string t) {
      if (s.length() != t.length()) return false;
      unordered_map<char, int> letter_to_count_s;
      unordered_map<char, int> letter_to_count_t;
      for (int i = 0; i < s.length(); i++) {
        letter_to_count_s[s[i]] += 1;
      }
      for (int i = 0; i < t.length(); i++) {
        letter_to_count_t[t[i]] += 1;
      }
      for (int i = 0; i < s.length(); i++) {
        if (letter_to_count_s[s[i]] !=letter_to_count_t[s[i]]) {
          return false;
        }
      }
      return true;
    }
};

class Solution2 {
public:
    bool isAnagram(string s, string t) {
      sort(s.begin(), s.end());
      sort(t.begin(), t.end());
      return s == t;
    }
};