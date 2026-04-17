class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int>mpp;

        string numStr = to_string(nums[0]);
        reverse(numStr.begin(), numStr.end());
        int num = stoi(numStr);

        mpp[num] = 0;

        int result = INT_MAX;

        for(int i=1; i<n; i++){
            if(mpp.find(nums[i]) != mpp.end()){
                result = min(result, abs(i-mpp[nums[i]]));
            }
            string numStr = to_string(nums[i]);
            reverse(numStr.begin(), numStr.end());
            int num = stoi(numStr);

            mpp[num] = i;
        }

        return result == INT_MAX ? -1 : result;
    }
};