/*
121. Best Time to Buy and Sell Stock
Easy

15810

529

Add to List

Share
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/
#include<math.h>
class Solution {

public:
    int maxProfit(vector<int>& prices) {
        // Approach-> 1
        int minSoFar = prices[0];
        int maxSoFar = 0;
        
        for(int i = 0; i < prices.size(); i++){
            minSoFar = min(minSoFar, prices[i]);
            int profit = prices[i] - minSoFar;
            maxSoFar = max(maxSoFar, profit);
        }
        
        return maxSoFar;
        
       // Approach -> 2;
        int buy = prices[0];
        int maxProfit = 0;
        
        for(int i = 1; i < prices.size(); i++){
            int sell = prices[i];
            int profit = sell - buy;
            if(profit < 0){
                buy = sell;
            }
            maxProfit = max(maxProfit, profit);
        }
        
        return maxProfit;
    }
};
