#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int left_ptr = 0;
      int right_ptr = 1;
      int max_profit = 0;
      while(right_ptr < prices.size()) {
        int selling_price = prices.at(right_ptr);
        int buying_price = prices.at(left_ptr);
        if (selling_price > buying_price) {
          int current_profit = selling_price - buying_price;
          max_profit = current_profit > max_profit ? current_profit : max_profit;
        } else {
          left_ptr = right_ptr;
        }
        right_ptr++;
      }
      return max_profit;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
      int min_price = prices[0];
      int max_profit = 0;
      for(int i =1; i < prices.size(); i++) {
        max_profit = (prices[i] - min_price) > max_profit ? (prices[i] - min_price) : max_profit;
        min_price = prices[i] < min_price? prices[i]: min_price;
      }
      return max_profit;
    }
};
