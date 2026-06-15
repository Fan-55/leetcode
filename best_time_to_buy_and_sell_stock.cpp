#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int max_profit = 0;
      int l_ptr = 0;
      for (int r_ptr = 1; r_ptr < prices.size(); r_ptr++) {
        int buy_price = prices.at(l_ptr);
        int sell_price = prices.at(r_ptr);
        if (sell_price < buy_price) {
          l_ptr = r_ptr;
        } else {
          int current_profit = sell_price - buy_price;
          max_profit = max(current_profit, max_profit);
        }
      } 
      return max_profit;
    }
};

int main () {
  vector<int> prices = { 7,1,5,3,6,4 };
  Solution s;
  int result = s.maxProfit(prices);
  cout << "expected max profix = 5" << endl;
  cout << "max profit is " << result << endl;
  return 0;
}
