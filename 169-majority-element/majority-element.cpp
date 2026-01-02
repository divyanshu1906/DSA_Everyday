class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int number = nums[0];
        int numCount = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] != number) numCount--;
            else numCount++;

            if(numCount == 0){
                number = nums[i];
                numCount = 1;
            }
        }

        return number;
    }
};