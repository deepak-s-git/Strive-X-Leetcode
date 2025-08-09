// Problem: Given an array where prices[i] is the price of a stock on day i, 
//          find the maximum profit by choosing a single day to buy and a single day to sell.
// Approach: 
// 1. Track the lowest price so far (bestBuy).
// 2. At each day, calculate the profit if sold today (prices[i] - bestBuy).
// 3. Update maxProfit whenever a better profit is found.
// Time Complexity: O(n), Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;          // best profit so far
        int bestBuy = prices[0];    // lowest price seen so far

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]); // update lowest price
        }

        return maxProfit;
    }
};
