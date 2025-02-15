class Solution {
public:
    bool recursive(int i, int currSum, string s, int num, vector<vector<int>>&dp){
        if(i==s.length()){
            return currSum==num;
        }
        if(currSum > num) return false;
        if(dp[i][currSum] != -1) return dp[i][currSum];
        bool possible = false;
        for(int j=i; j<s.length(); j++){
            string str = s.substr(i, j-i+1);
            int val = stoi(str);
            possible = possible || recursive(j+1, currSum+val, s, num, dp);
            if(possible){
                return true;
            }
        }
        return dp[i][currSum] = possible;
    }
    int punishmentNumber(int n) {
       int punish = 0;
        for(int num=1; num<=n; num++){
            int sq = num*num;
            string s = to_string(sq);
            vector<vector<int>>dp(s.length(), vector<int>(num+1, -1));
            if(recursive(0, 0, s, num, dp)){
                punish += sq;
            }
        }
        return punish;
    }
};