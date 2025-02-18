class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minSum = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int down = matrix[i][j] + dp[i-1][j];
                int left = INT_MAX;
                if(j>0){
                    left = matrix[i][j] + dp[i-1][j-1];
                }
                int right = INT_MAX;
                if(j<n-1){
                    right = matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min(down, min(left, right));
            }
        }
        for(int j=0; j<n; j++){
            minSum = min(minSum, dp[n-1][j]);
        }
        return minSum;
    }
};