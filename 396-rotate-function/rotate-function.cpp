class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        int currVal = 0;
        for(int i=0; i<n; i++){
            currVal += (nums[i] * i);
        }

        int maxVal = currVal;
        for(int i=n-1; i>0; i--){
            currVal -= nums[i] * (n-1);
            currVal += sum - nums[i];

            maxVal = max(currVal, maxVal);
        }

        return maxVal;
    }
};