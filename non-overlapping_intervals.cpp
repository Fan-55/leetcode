#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int ans = 0;
      sort(intervals.begin(), intervals.end(),[](vector<int>a, vector<int>b){ return a[0] < b[0]; });
      int prev_end = intervals[0][1];
      for(int i = 1; i < intervals.size(); i++) {
        /// if overlapping -> remove the one has larger end
        if (prev_end > intervals[i][0] ) {
          if (prev_end >= intervals[i][1]) {
            prev_end = intervals[i][1];
          }
          ans++;
        } else {
          prev_end = intervals[i][1];
        }
      }
      return ans;
    }
};

/// prev |-----------|
/// prev |---------------------|
/// curr      |----------|
/// next        |--|