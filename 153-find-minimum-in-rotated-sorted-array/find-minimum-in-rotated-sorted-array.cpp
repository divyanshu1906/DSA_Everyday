class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int minEle = INT_MAX;

        for(int i=0; i<n; i++){
            minEle = min(minEle, nums[i]);
        }

        return minEle;
    }
};