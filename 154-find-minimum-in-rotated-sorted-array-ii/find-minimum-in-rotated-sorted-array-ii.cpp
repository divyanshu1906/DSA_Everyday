class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(nums[i], ans);
        }

        return ans;
    }
};