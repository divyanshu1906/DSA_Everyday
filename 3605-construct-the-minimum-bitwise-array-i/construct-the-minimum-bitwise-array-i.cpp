class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);

        for(int i=0; i<n; i++){
            int num = nums[i];
            int prevNum = nums[i]-1;

            while(prevNum != 0){
                if((num | prevNum) == nums[i]){
                    ans[i] = prevNum;
                }
                num = prevNum;
                prevNum--;
            }
        }

        return ans;
    }
};