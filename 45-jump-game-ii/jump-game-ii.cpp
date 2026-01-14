class Solution {
public:
    int findinMinJump(int idx, vector<int>& nums, vector<int>&dp){
        if(idx >= nums.size()) return 0;

        if(dp[idx] != -1) return dp[idx];
        int jump = nums[idx] + idx+1;

        if(jump >= nums.size()) return dp[idx] = 1;
        
        int minJump = 1e9+7;

        for(int i=idx+1; i<jump; i++){
            minJump = min(minJump, 1 + findinMinJump(i, nums, dp));
        }

        return dp[idx] = minJump;
    }
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        vector<int>dp(nums.size(), -1);

        return findinMinJump(0, nums, dp);
    }   
};