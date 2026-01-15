class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int prevJumpMax = nums[0];

        if(n==1) return 0;

        if(prevJumpMax >= n-1) return 1;

        int jump = 1;
        int currJumpMax = 0;

        for(int i=1; i<n; i++){
            currJumpMax = max(currJumpMax, nums[i]+i);

            if(currJumpMax >= n-1) return jump+1;

            if(i == prevJumpMax){
                prevJumpMax = currJumpMax;
                jump++;
                currJumpMax = 0;
            }
        }

        return 0;
    }
};