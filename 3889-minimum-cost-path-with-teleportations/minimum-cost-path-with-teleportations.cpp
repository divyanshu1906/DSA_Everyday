class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int maxEle = INT_MIN;
        for (const auto& row : grid) {
            maxEle = max(maxEle, *max_element(row.begin(), row.end()));
        }

        vector<int>teleportation(maxEle+1, INT_MAX);

        vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
        dp[n-1][m-1] = 0;

        for(int tel = 0; tel<=k; tel++){
            
            for(int i=n-1; i>=0; i--){
                for(int j=m-1; j>=0; j--){

                    if(j+1 < m){
                        dp[i][j] = min(dp[i][j], grid[i][j+1] + dp[i][j+1]);
                    }

                    if(i+1 < n){
                        dp[i][j] = min(dp[i][j], grid[i+1][j] + dp[i+1][j]);
                    }

                    if(tel > 0){
                        dp[i][j] = min(dp[i][j], teleportation[grid[i][j]]);
                    }
                }
            }

            for(int p=0; p<n; p++){
                for(int q=0; q<m; q++){
                    teleportation[grid[p][q]] = min(teleportation[grid[p][q]], dp[p][q]);
                }
            }

            for(int p=1; p<teleportation.size(); p++){
                teleportation[p] = min(teleportation[p], teleportation[p-1]);
            }
        }

        return dp[0][0];
    }
};