class Solution {
public:
    const int MOD = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for(auto &query : queries){
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            int idx = l;
            while(idx < n && idx <= r){
                nums[idx] = (1LL * nums[idx] * v) % MOD;
                idx += k;
            }
        }

        int result = 0;
        for(auto &num : nums){
            result ^= num;
        }

        return result;
    }
};