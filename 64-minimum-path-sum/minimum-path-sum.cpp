class Solution {
public:
    int n, m;
    vector<vector<int>>directions = {{0, -1}, {-1, 0}};
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(row==0 && col==0) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int minSum = INT_MAX;
        for(auto &dir : directions){
            int row_ = row + dir[0];
            int col_ = col + dir[1];
            if(row_>=0 && row_<n && col_>=0 && col_<m){
                minSum = min(minSum , grid[row][col] + dfs(row_, col_, grid, dp));
            }
        }
        return dp[row][col]=minSum;
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m));
        dp[0][0] = grid[0][0];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0)continue;
                int minSum = INT_MAX;
                for(auto &dir : directions){
                    int row = i + dir[0];
                    int col = j + dir[1];
                    if(row>=0 && row<n && col>=0 && col<m){
                        minSum = min(minSum, grid[i][j] + dp[row][col]);
                    }
                }
                dp[i][j] = minSum;
            }
        }
        return dp[n-1][m-1];
    }
};