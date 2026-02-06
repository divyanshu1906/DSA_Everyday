class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        for(int i=0; i<n; i++){
            long long val = (long long)nums[i] * k;

            int nextGreater = upper_bound(nums.begin(), nums.end(), val) - nums.begin();

            ans = min(ans, (n - nextGreater + i));

            if(nextGreater == n) break;
        }

        return ans;
    }
};