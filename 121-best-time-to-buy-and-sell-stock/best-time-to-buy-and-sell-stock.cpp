class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int minBuyPrice = prices[0];
        int profit = 0;
        for(int i=1; i<n; i++){
            minBuyPrice = min(minBuyPrice, prices[i]);

            profit = max(profit, prices[i] - minBuyPrice);
        }

        return profit;
    }
};