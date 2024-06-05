#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> ans;
      unordered_map<string, vector<string>> sorted_anagram_key_to_original_str;
      for (int i = 0; i < strs.size(); i++) {
        string current_str = strs[i];
        sort(current_str.begin(), current_str.end());
        sorted_anagram_key_to_original_str[current_str].push_back(strs[i]);
      }
      for (auto pair: sorted_anagram_key_to_original_str) {
        ans.push_back(pair.second);
      }
      return ans;
    }
};