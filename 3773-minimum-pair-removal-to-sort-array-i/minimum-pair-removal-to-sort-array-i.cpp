class Solution {
public:
    int minPairSum(vector<int>&nums){
        int n = nums.size();
        int minVal = INT_MAX;
        int idx = -1;
        for(int i=0; i<n-1; i++){
            int currSum = nums[i] + nums[i+1];

            if(minVal > currSum){
                minVal = currSum;
                idx = i;
            }
        }

        return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while(!is_sorted(nums.begin(), nums.end())){
            int index = minPairSum(nums);

            nums[index] = nums[index] + nums[index+1];

            nums.erase(nums.begin()+index+1);

            operations++;
        }

        return operations;
    }
};