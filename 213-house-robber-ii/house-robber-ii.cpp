class Solution {
public:
    int houseRobber(int index, vector<int>&nums, vector<int>&dp){
        if(index<0) return 0;
        if(index==0) return nums[0];
        if(dp[index] != -1) return dp[index];
        
        int take = nums[index] + houseRobber(index-2, nums, dp);
        int notTake = 0 + houseRobber(index-1, nums, dp);
        return dp[index] =  max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n, -1), dp2(n, -1);
        vector<int>nums1(nums.begin(), nums.end()-1);
        int case1 = houseRobber(nums1.size()-1, nums1, dp1);

        vector<int>nums2(nums.begin()+1, nums.end());
        int case2 = houseRobber(nums2.size()-1, nums2, dp2);
        return max(case1, case2);
    }
};