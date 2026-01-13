class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        int till = k % n;

        reverse(nums.end() - till, nums.end());
        reverse(nums.begin(), nums.end()-till);
        reverse(nums.begin(), nums.end());
    }
};