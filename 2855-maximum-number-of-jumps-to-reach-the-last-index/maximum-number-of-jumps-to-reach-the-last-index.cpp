class Solution {
public:
    int n;
    int solve(int i, vector<int>&nums, int target, vector<int>&dp){
        if(i == n-1) return 0;

        if(dp[i] != -1) return dp[i];

        int maxAns = INT_MIN;
        for(int j=i+1; j<n; j++){

            if (abs(nums[j] - nums[i]) <= target) {

                int next = solve(j, nums, target, dp);

                if (next != INT_MIN) {
                    maxAns = max(maxAns, 1 + next);
                }
            }
        }

        return dp[i] = maxAns ;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();

        vector<int>dp(n, -1);

        int ans = solve(0, nums, target, dp);

        return ans == INT_MIN ? -1 : ans;
    }
};