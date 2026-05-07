class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        vector<int> prefixHighest(n);
        prefixHighest[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixHighest[i] = max(prefixHighest[i-1], nums[i]);
        }
        
        vector<int> suffixLowest(n);
        suffixLowest[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffixLowest[i] = min(suffixLowest[i+1], nums[i]);
        }
        
        ans[n-1] = prefixHighest[n-1];
        for (int i = n-2; i >= 0; i--) {
            ans[i] = prefixHighest[i];

            if(ans[i] > suffixLowest[i+1]){
                ans[i] = max(ans[i], ans[i+1]);
            }
        }
        
        return ans;
            
    }
};