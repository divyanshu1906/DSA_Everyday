class Solution {
public:
    int n, m;
    int findingMinSum(int idx1, int idx2, string &s1, string &s2, vector<vector<int>>&dp){
        if(idx1 == n || idx2 == m){
            int rem = 0;
            if(idx1 < n){
                for(int i = idx1; i<n; i++){
                    rem += (int)s1[i] ;
                }
            }
            else if(idx2 < m){
                for(int i=idx2; i<m; i++){
                    rem += (int)s2[i] ;
                }
            }
            return rem;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int ans = INT_MAX;
        if(s1[idx1] == s2[idx2]){
            return dp[idx1][idx2] =  findingMinSum(idx1+1, idx2+1, s1, s2, dp);
        }

        int skipFromFirstString  = (int)s1[idx1] + findingMinSum(idx1+1, idx2, s1, s2, dp);
        int skipFromSecondString = (int)s2[idx2] + findingMinSum(idx1, idx2+1, s1, s2, dp);

        ans = min({ans, skipFromFirstString, skipFromSecondString});

        return dp[idx1][idx2] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();

        vector<vector<int>>dp(n, vector<int>(m, -1));

        return findingMinSum(0, 0, s1, s2, dp);
    }
};