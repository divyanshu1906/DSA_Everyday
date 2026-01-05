class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long ans = 0;
        int minEle = INT_MAX;
        int negCount = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] < 0) {
                    negCount++;
                }
                ans += abs(matrix[i][j]);
                minEle = min(minEle, abs(matrix[i][j]));
            }
        }

        if(negCount % 2 != 0){
            ans -= 2 * minEle;
        }

        return ans;
    }
};