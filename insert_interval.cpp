#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> result;
      for (int i = 0; i < intervals.size(); i++) {
        /// new interval is before current interval => insert new interval and rest of the intervals to the result
        //        |----|       current interval
        // |----|              new interval
        if (newInterval[1] < intervals[i][0]) {
          result.push_back(newInterval);
          vector<vector<int>>::iterator it = intervals.begin() + i;
          result.insert(result.end(), it, intervals.end());
          return result;
        }
        /// new interval is after current interval => insert current interval to the result since there is nothing we can do about it
        // |----|                   current interval
        //          |----|          new interval
        else if (newInterval[0] > intervals[i][1]) {
          result.push_back(intervals[i]);
        }
        /// new interval is overlapping current interval => merge interval by getting smaller head and bigger tail
        ///  |----|          current interval
        ///     |----|       possible new interval 1
        /// |---------|      possible new interval 2
        /// |----|           possible new interval 3
        else {
          newInterval[0] = min(newInterval[0], intervals[i][0]);
          newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
      }
      result.push_back(newInterval);
      return result;
    }
};