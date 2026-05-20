class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);

        unordered_map<int, int>mpp;

        for(int i=0; i<n; i++){
            mpp[A[i]]++;
            mpp[B[i]]++;

            int count = 0;

            for(auto &[ele, num] : mpp){
                if(num==2){
                    count++;
                }
            }

            ans[i] = count;
        }

        return ans;
    }
};