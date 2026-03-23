class Solution {
public:
    int n , m;
    const int MOD = 1e9+7;
    typedef long long ll;

    pair<ll, ll> findingMaxProduct(int i, int j, vector<vector<int>>&grid, vector<vector<pair<ll, ll>>>&dp){
        if(i==m-1 && j==n-1){
            return {grid[i][j], grid[i][j]};
        }

        if(dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) return dp[i][j];

        ll maxVal  = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if(i+1 < m){
            auto [downMax, downMin] = findingMaxProduct(i+1, j, grid, dp);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        if(j+1 < n){
            auto [rightMax, rightMin] = findingMaxProduct(i, j+1, grid, dp);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return dp[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<pair<ll, ll>>>dp(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));

        auto [maxProd, minProc] = findingMaxProduct(0, 0, grid, dp);


        if(maxProd < 0) return -1;
        
        return maxProd % MOD;
    }
};