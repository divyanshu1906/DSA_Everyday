class Solution {
public:
    int n, m;
    vector<vector<int>>directions = {{-1, 0}, {0, -1}};
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
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return dfs(n-1, m-1, obstacleGrid, dp);
    }
};