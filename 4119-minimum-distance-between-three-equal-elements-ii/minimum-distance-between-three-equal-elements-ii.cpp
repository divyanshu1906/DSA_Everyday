class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>>mpp;

        int ans = n;

        for(int i=0; i<n; i++){
            mpp[nums[i]].push_back(i);
        }

        for(auto [num, vec] : mpp){
            int m = vec.size();
            if(m > 2){
                sort(vec.begin(), vec.end());
                
                for(int i=0; i<m-2; i++){
                    int j = i+2;
                    ans = min(ans, vec[j]-vec[i]);
                }
            }
        }

        return ans == n ? -1 : ans*2;
    }
};