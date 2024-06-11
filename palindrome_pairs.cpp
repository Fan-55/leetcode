#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
      vector<vector<int>> ans;
      unordered_map<string, int> word_to_index;
      for (int i = 0; i < words.size(); i++) {
        word_to_index[words[i]] = i;
      }
      for (int i = 0; i < words.size(); i++) {
        /// Empty string
        if (words[i] == "") {
          for (int j = 0; j < words.size(); j++) {
            if (i != j && isPalindrome(words[j], 0, words[j].size()-1)) {
              ans.push_back({i, j});
              ans.push_back({j, i});
            }
          }
          continue;
        }
        /// Reversed word exists
        string word = words[i];
        reverse(word.begin(), word.end());
        if (word_to_index.contains(word) && word_to_index[word] != i) {
          ans.push_back({i, word_to_index[word]});
        }
        /// Find prefix (cbaa) + aaabc
        for(int k = 0; k < words[i].length(); k++) {
          if (isPalindrome(words[i], 0, k)) {
            string remainder = words[i].substr(k+1);
            if (remainder.length()) {
              reverse(remainder.begin(), remainder.end());
              if (word_to_index.contains(remainder)) {
                ans.push_back({word_to_index[remainder], i});
              }
            }
          }
        }
        /// Find suffix bcaaa + aacb(suffix)
        for(int k = words[i].length() - 1; k >= 0; k--) {
          if (isPalindrome(words[i], k, words[i].length() - 1)) {
            string remainder = words[i].substr(0, k);
            if (remainder.length()) {
              reverse(remainder.begin(), remainder.end());
              if (word_to_index.contains(remainder)) {
                ans.push_back({i, word_to_index[remainder]});
              }
            }
          }
        }
      }
      return ans;
    }

    bool isPalindrome(const string& str, int l, int r) {
      if (!str.length()) return false;
      while(l <= r) {
        if (str[l] == str[r]) {
          l++;
          r--;
        } else {
          return false;
        }
      }
      return true;
    }
};
