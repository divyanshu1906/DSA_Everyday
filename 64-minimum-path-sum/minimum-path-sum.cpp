class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>directions = {{0, -1}, {-1, 0}};
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