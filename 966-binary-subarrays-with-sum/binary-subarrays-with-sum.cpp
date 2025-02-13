class Solution {
public:
    int sumEqualTo(vector<int>& nums, int goal){
        int l=0, r=0, count=0;
        long sum=0;
        while(r<nums.size()){
            sum += nums[r];
            while(l<=r && sum > goal){
                sum -= nums[l];
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        return sumEqualTo(nums, goal) - sumEqualTo(nums, goal-1);
    }
};