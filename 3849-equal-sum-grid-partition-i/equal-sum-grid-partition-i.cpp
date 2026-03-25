class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        long long totalSum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                totalSum += grid[i][j];
            }
        }

        if(totalSum % 2 != 0) return false;

        long long horizontalSum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                horizontalSum += grid[i][j];
            }

            if(horizontalSum == (totalSum/2)) return true;
        }

        long long verticalSum = 0;
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                verticalSum += grid[i][j];
            }

            if(verticalSum == (totalSum/2)) return true;
        }

        return false;
    }
};