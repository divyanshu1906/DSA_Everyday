class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int>mpp;
        vector<int>ans;

        for(int i=0; i<n; i++){
            int half = target - nums[i];
            if(mpp.find(half) != mpp.end()){
                ans.push_back(mpp[half]);
                ans.push_back(i);
                break;
            }
            else mpp[nums[i]] = i;
        }

        return ans;
    }
};