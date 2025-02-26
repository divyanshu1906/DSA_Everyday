class Solution {
public:
    void maxSumAbsolute(int idx, vector<int>&nums, int &maxSum, int sum){
        if(idx<0){
            maxSum = max(maxSum, abs(sum));
            return;
        }
        maxSumAbsolute(idx-1, nums, maxSum, sum+nums[idx]);
        maxSumAbsolute(idx-1, nums, maxSum, sum);
        
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, maxSubarraySum = 0, minSubarraySum = 0;

        for (int num : nums) {
            maxSum = max(num, maxSum + num);
            maxSubarraySum = max(maxSubarraySum, maxSum);

            minSum = min(num, minSum + num);
            minSubarraySum = min(minSubarraySum, minSum);
        }

        return max(abs(maxSubarraySum), abs(minSubarraySum));
    }
};