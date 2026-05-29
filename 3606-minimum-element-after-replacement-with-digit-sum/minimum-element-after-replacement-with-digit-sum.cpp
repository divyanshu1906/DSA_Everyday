class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;

        for(int i=0; i<n; i++){
            string numStr = to_string(nums[i]);

            int sum = 0;
            for(int j=0; j<numStr.length(); j++){
                sum += numStr[j] - '0';
            }

            ans = min(ans, sum);
        }

        return ans;
    }
};