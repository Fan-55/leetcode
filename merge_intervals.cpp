#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      vector<vector<int>> res;
      // sort intervals in ascending order
      sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
      });
      vector<int> target = intervals[0];
      for (int i = 1; i < intervals.size(); i++) {
        if (target[1] < intervals[i][0]) {
          res.push_back(target);
          target = intervals[i];
        } else { // merge
          target = {target[0], max(target[1], intervals[i][1])};
        }
      }
      res.push_back(target);
      return res;
    }
};