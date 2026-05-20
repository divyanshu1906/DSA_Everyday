class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);

        unordered_map<int, int>mpp;

        int common = 0;

        for(int i=0; i<n; i++){

            if(++mpp[A[i]] == 2) common++;
            
            if(++mpp[B[i]] == 2) common++;

            ans[i] = common;
        }

        return ans;
    }
};