class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxSum = -1;
        unordered_map<int, vector<int>> mpp;
        for (int num : nums) {
            int sum = 0, temp = num;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            if (mpp[sum].size() == 2) {
                if (num > mpp[sum][0]) {
                    mpp[sum][1] = mpp[sum][0]; 
                    mpp[sum][0] = num;
                } else if (num > mpp[sum][1]) {
                    mpp[sum][1] = num;
                }
            } else {
                mpp[sum].push_back(num);
                if (mpp[sum].size() == 2 && mpp[sum][0] < mpp[sum][1]) {
                    swap(mpp[sum][0], mpp[sum][1]); 
                }
            }

            if (mpp[sum].size() == 2) {
                maxSum = max(maxSum, mpp[sum][0] + mpp[sum][1]);
            }
        }

        return maxSum;
    }
};