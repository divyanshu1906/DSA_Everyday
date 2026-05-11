class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans;

        for(int i=0; i<n; i++){
            string strNum = to_string(nums[i]);
            for(int j=0; j<strNum.size(); j++){
                int num = strNum[j]-'0';
                ans.push_back(num);
            }
        }

        return ans;
    }
};