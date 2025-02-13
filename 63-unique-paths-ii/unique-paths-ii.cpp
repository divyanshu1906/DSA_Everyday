class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>directions = {{-1, 0}, {0, -1}};
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