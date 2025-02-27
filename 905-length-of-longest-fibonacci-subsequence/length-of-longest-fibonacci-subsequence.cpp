class Solution {
public:
    int solve(int i, int j, vector<int>&arr, unordered_map<int, int>&mpp, vector<vector<int>>&dp){
        int sum = arr[j] - arr[i];
        if(dp[i][j] != -1) return dp[i][j];
        if(mpp.count(sum) && mpp[sum] < i){
            int k = mpp[sum];
            return dp[i][j] = 1 + solve(k, i, arr, mpp, dp);
        }
        return dp[i][j] = 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n, 2));

        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]] = i;
        }

        int maxLen = 0;
        for(int i=1; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = arr[j] - arr[i];
                if(mpp.count(sum) && mpp[sum] < i){
                    int k = mpp[sum];
                    dp[i][j] = 1 + dp[k][i];
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen>2?maxLen : 0;
    }
};