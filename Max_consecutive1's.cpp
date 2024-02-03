class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int consecutive = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                count += 1;
                if(count > consecutive)
                {
                    consecutive = count;
                }
            }
            else{
                count =0;
            }
        }
        return consecutive;
    }
};
