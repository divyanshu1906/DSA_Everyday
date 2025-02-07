class Solution {
public:
    int memoization(int n, vector<int>&dp){
        if(n==0)return 1;
        if(dp[n] != -1) return dp[n];

        int oneStep = memoization(n-1, dp);
        int twoStep = 0;
        if(n-2>=0){
            twoStep = memoization(n-2, dp);
        }
        return dp[n] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return memoization(n, dp);
    }
};