class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;

        sort(nums.begin(), nums.end());

        int i=0, j=k-1;
        int ans = INT_MAX;

        while(j<n){
            ans = min(ans, nums[j] - nums[i]);
            j++;
            i++;
        }

        return ans;
    }
};