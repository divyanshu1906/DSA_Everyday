class Solution {
public:
    int solve(int i, int j, int k, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>>&dp){
        if(i>=m || j>=n) return INT_MIN;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        if(k==0 && grid[i][j] != 0) return dp[i][j][k] = INT_MIN;

        int newK = (k - (grid[i][j] == 0 ? 0 : 1));

        if(i==m-1 && j==n-1) return dp[i][j][k] = grid[i][j];

        int right = solve(i, j+1, newK, grid, m, n, dp);
        int down  = solve(i+1, j, newK, grid, m, n, dp);

        int best = max(right, down);

        if(best == INT_MIN) return dp[i][j][k] = INT_MIN;

        return dp[i][j][k] = grid[i][j] + best;

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        int ans = solve(0, 0, k, grid, m, n, dp) ;

        return ans == INT_MIN ? -1 : ans;
    }
};