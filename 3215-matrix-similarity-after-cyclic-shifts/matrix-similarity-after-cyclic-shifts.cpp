class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>rotatedMat(m, vector<int>(n, 0));

        int idxChange = k%n;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i%2==0){
                    int j_ = ((j-idxChange) + n)%n;
                    rotatedMat[i][j_] = mat[i][j];
                }else{
                    int j_ = (j+idxChange) % n;
                    rotatedMat[i][j_] = mat[i][j]; 
                }
            }
        }

        return rotatedMat == mat;
    }
};