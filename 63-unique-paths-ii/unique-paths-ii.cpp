class Solution {
public:
    vector<vector<int>>directions = {{-1, 0}, {0, -1}};
    int n, m;
    int dfs(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        if(row==0 && col==0) return 1;
        int sum = 0;
        if(dp[row][col] != -1) return dp[row][col];
        for(auto &dir : directions){
            int row_ = row + dir[0];
            int col_ = col + dir[1];
            if(row_>=0 && row_<n && col_>=0 && col_<m && obstacleGrid[row_][col_]!=1){
                sum += dfs(row_, col_, obstacleGrid, dp);
            }
        }
        return dp[row][col] = sum;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1) return 0;
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[0][0] = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
            int sum = 0;
            if(i==0 && j==0) continue;
                for(auto &dir : directions){
                    int row_ = i + dir[0];
                    int col_ = j + dir[1];
                    if(row_>=0 && row_<n && col_>=0 && col_<m && obstacleGrid[row_][col_]!=1){
                        sum += dp[row_][col_];
                    }
                }
                dp[i][j] = sum;
            }
        }
        return dp[n-1][m-1];
    }
};