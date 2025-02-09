class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long  n = nums.size();
        // long long  totalPairs = (n*(n-1))/2;
        long long  goodPairs = 0;
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            long long val = nums[i]-i;
            mpp[val]++;
        }
        for(auto &it : mpp){
            long long  freq = it.second;
            if(freq > 1){
                goodPairs += freq * (freq-1)/2;
            }
        }
        return (n*(n-1))/2 - goodPairs;
    }
};