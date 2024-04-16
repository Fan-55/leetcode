#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int remaining = 0;
      int ans = 0;
      int sum_of_gas = 0;
      int sum_of_cost = 0;
      for (int gas_of_station: gas) {
        sum_of_gas+=gas_of_station;
      }

      for (int cost_of_station: cost) {
        sum_of_cost += cost_of_station;
      }

      if (sum_of_cost > sum_of_gas) {
        return -1;
      }

      for (int i = 0; i < gas.size(); i++) {
        remaining += (gas.at(i) - cost.at(i));
        if (remaining < 0) {
          remaining = 0;
          ans = i + 1;
        }
      }
      return ans;
    }
};