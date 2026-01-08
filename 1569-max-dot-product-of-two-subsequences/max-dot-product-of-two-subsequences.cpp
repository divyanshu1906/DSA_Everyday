class Solution {
public:
    int findingMaxDotProduct(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(idx1 == nums1.size() || idx2 == nums2.size()) return INT_MIN;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int take = nums1[idx1] * nums2[idx2];
        int next = findingMaxDotProduct(idx1+1, idx2+1, nums1, nums2, dp);

        if(next != INT_MIN){
            take = max(take, nums1[idx1] * nums2[idx2] + next);
        }
        
        int notTake1 = findingMaxDotProduct(idx1+1, idx2, nums1, nums2, dp);
        int notTake2 = findingMaxDotProduct(idx1, idx2+1, nums1, nums2, dp);

        return dp[idx1][idx2] = max({take, notTake1, notTake2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>>dp(n, vector<int>(m, -1));
        return findingMaxDotProduct(0, 0, nums1, nums2, dp);
    }
};