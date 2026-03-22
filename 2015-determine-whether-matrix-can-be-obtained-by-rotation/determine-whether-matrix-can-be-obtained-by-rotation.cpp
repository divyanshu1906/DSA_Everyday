class Solution {
public:
    void rotate90(vector<vector<int>>& mat){
        int n = mat.size();

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(auto &row : mat){
            reverse(row.begin(), row.end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for(int c=1; c<=4; c++){
            bool isEqual = true;

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][j] != target[i][j]){
                        isEqual = false;
                        break;
                    }
                }
                if(!isEqual) break;
            }

            if(isEqual) return true;

            rotate90(mat);
        }

        return false;
        
    }
};