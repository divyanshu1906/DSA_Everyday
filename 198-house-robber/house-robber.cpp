class Solution {
public:
    int houseRobber(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i<0) return 0;
        if(i==0) return nums[i];
        if(dp[i] != -1) return dp[i];
        int maxValue = INT_MIN;
        int take = 0;
        take = nums[i] + houseRobber(i-2, n, nums, dp);
        int notTake = 0 + houseRobber(i-1, n, nums, dp);
        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return houseRobber(n-1, n, nums, dp);
    }
};