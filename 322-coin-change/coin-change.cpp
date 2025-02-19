class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sum = 0;
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 1e9));
        for(int i=0; i<n; i++){
            dp[i][0] = 0;
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<=amount; j++){
                int take = 1e9;
                if(j>=coins[i]){
                    take = 1 + dp[i][j-coins[i]];
                }
                int notTake =(i>0) ? dp[i-1][j] : 1e9;
                dp[i][j] = min(take, notTake);
            }
        }
        return dp[n-1][amount] > amount ? -1 : dp[n-1][amount];
    }
};