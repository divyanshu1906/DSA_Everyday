class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, pair<int, int>>mpp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mpp[mat[i][j]] = {i,j};
            }
        }
        vector<int>row(n,0), col(m,0);
        for(int i=0; i<arr.size(); i++){
            int num = arr[i];
            pair<int, int> position = mpp[num];
            int i_ = position.first;
            int j_ = position.second;
            row[i_]++;
            col[j_]++;
            if(row[i_] == m || col[j_] == n)return i;
        }
        return -1;
    }
};