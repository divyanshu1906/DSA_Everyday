class Solution {
public:
    long long solve(int i, int j, vector<int>& robot, vector<int>& position, vector<vector<long long>>&dp){
        if(i >= robot.size()) return 0;
        if(j >= position.size()) return 1e15;

        if(dp[i][j] != -1) return dp[i][j];

        long long take = abs((long long)robot[i] - position[j]) + solve(i+1, j+1, robot, position, dp);
        long long notTake = solve(i, j+1, robot, position, dp);

        return dp[i][j] = min(take, notTake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();

        vector<int>position;

        for(int i=0; i<factory.size(); i++){
            int pos = factory[i][0];
            int limit = factory[i][1];

            while(limit--){
                position.push_back(pos);
            }
        }
        int m = position.size();

        vector<vector<long long>>dp(n, vector<long long>(m, -1));

        return solve(0, 0, robot, position, dp);
    }
};