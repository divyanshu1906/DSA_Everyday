class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, 0);
        dp[1] = nums[0];
        for(int i=2; i<n+1; i++){
            int take = nums[i-1] + dp[i-2];
            int notTake = 0 + dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[n];
    }
};