class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int smallestNum = INT_MAX;
        int secondSmallestNum = INT_MAX;

        for(int i=1; i<n; i++){
            if(nums[i] < smallestNum){
                secondSmallestNum = smallestNum;
                smallestNum = nums[i];
            }
            else if(nums[i] < secondSmallestNum){
                secondSmallestNum = nums[i];
            }
        }

        return nums[0] + smallestNum + secondSmallestNum;
    }
};