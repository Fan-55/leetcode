#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int left = 0;  // for buying
        int right = 1; // for selling
        int highestProfit = 0;
        while(right < prices.size()) {
            if(prices[right] > prices[left]) {
                int profit = prices[right] - prices[left];
                if(profit > highestProfit) {
                    highestProfit = profit;
                }
                right = right + 1;
            } else if(prices[right] < prices[left]) {
                left = right;
                right = right + 1;
            }
        }
        return highestProfit;
    }
};
