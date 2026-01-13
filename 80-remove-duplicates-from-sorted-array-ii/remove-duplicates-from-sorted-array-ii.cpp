class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0, k=1, numCount = 1;

        for(int i=1; i<n; i++){
            if(nums[i-1] == nums[i]) numCount++;
            else numCount = 1;

            if(numCount < 3){
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};