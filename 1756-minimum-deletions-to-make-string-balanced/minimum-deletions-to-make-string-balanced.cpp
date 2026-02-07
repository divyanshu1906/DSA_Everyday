class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int>nextA(n,0);

        for(int i=n-2; i>=0; i--){
            nextA[i] += nextA[i+1];
            if(s[i+1] == 'a'){
                nextA[i]++;
            }
        }

        int result = INT_MAX;
        int pastB = 0;
        for(int i=0; i<n; i++){
            result = min(result, nextA[i]+pastB);

            if(s[i] == 'b') pastB++;
        }

        return result;
    }
};