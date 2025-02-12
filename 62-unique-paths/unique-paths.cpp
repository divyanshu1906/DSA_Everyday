class Solution {
public:
    int initialRow, initialCol;
    int dfs(int row, int col, vector<pair<int,int>>&directions, vector<vector<int>>&dp){
        if(row==0 && col==0) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int sum = 0;
        for(auto &dir : directions){
            int row_ = row + dir.first;
            int col_ = col + dir.second;
            if(row_>=0 && row_ < initialRow && col_>=0 && col_ < initialCol){
                sum += dfs(row_, col_ , directions, dp);
            }
        }
        return dp[row][col] = sum;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, 1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};