class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i = 1;

        bool inclineFound = false;
        while(i<n && nums[i] > nums[i-1]){
            i++;
        }

        int p = i-1;
        while(i<n && nums[i] < nums[i-1]){
            i++;
        }

        int q = i-1;
        while(i<n && nums[i] > nums[i-1]){
            i++;
        }

        int flag = i-1;

        return ((p != 0) && (q != p) && (flag == n-1 && flag != q));
    }
};