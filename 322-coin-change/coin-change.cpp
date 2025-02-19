class Solution {
public:
    int findingMinimumCoinChange(int idx, vector<int>& coins, int amount, int &sum, vector<vector<int>> &dp){
        if(idx<0 || sum>amount)  return 1e9;
        if(sum == amount){
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int sum_ = sum+coins[idx];
        int take = 1 + findingMinimumCoinChange(idx, coins, amount, sum_, dp);
        int notTake = 0+findingMinimumCoinChange(idx-1, coins, amount, sum, dp);
        return dp[idx][sum] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int sum = 0;
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount, -1));
        int ans = findingMinimumCoinChange(n-1, coins, amount, sum, dp);
        return ans > amount ? -1 : ans;
    }
};