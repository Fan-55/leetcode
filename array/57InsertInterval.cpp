#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> results;
        for(int i = 0; i < intervals.size(); i++) {
            if(newInterval[1] < intervals[i][0]) { // newInterval comes before current interval
                results.push_back(newInterval);
                for(int j = i; j < intervals.size(); j++) {
                    results.push_back(intervals[j]);
                }
                return results;
            } else if(newInterval[0] > intervals[i][1]) { // newInterval comes after current interval
                results.push_back(intervals[i]);
            } else { // newInterval should be merged with current interval
                vector<int> mergedInterval;
                mergedInterval.push_back(min(newInterval[0], intervals[i][0]));
                mergedInterval.push_back(max(newInterval[1], intervals[i][1]));
                newInterval = mergedInterval;
            }
        }
        results.push_back(newInterval);
        return results;
    }
};
