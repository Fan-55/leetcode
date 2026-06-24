#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<int> intervalToInsert = newInterval;
      vector<vector<int>> ans;
      for (vector<int> interval : intervals) {
        if (intervalToInsert.size() == 2) {
          int start = interval.at(0);
          int end = interval.at(1);
          int newStart = intervalToInsert.at(0);
          int newEnd = intervalToInsert.at(1);
          bool shouldMerge = newStart <= end && (newEnd >= end || newEnd >= start) ;
          bool shouldInsert = newEnd < start;
          if (shouldMerge) {
            intervalToInsert = {min(start, newStart), max(end, newEnd)};
          } else if (shouldInsert) {
            ans.push_back(intervalToInsert);
            ans.push_back(interval);
            intervalToInsert.clear();
          } else {
            ans.push_back(interval);
          }
        } else {
          ans.push_back(interval);
        }
      }
      if (intervalToInsert.size()) {
        ans.push_back(intervalToInsert);
      }
      return ans;
    }
};

void printer(vector<vector<int>>& intervals, vector<int>& newInterval) {
  Solution s;
  vector<vector<int>> ans = s.insert(intervals, newInterval);
  cout << "inserted result : [";
  for (vector<int> interval: ans) {
    cout << "[" << interval.at(0) << ", " << interval.at(1) << "]";
  }
  cout << " ]" << endl;;
}

int main () {
  vector<vector<int>> intervals = {{1, 3}, {6, 9}};
  vector<int> newInterval ={2,5};
  printer(intervals, newInterval);

  intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  newInterval ={4, 8};
  printer(intervals, newInterval);
  return 0;
}