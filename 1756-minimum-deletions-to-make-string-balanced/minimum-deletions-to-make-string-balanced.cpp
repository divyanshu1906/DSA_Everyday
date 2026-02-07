class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int nextA = 0;
        int result = INT_MAX;
        int pastB = 0;

        for(int i=n-1; i>=0; i--){
            if(s[i] == 'a'){
                nextA++;
            }
        }

        for(int i=0; i<n; i++){
            if(s[i] == 'a') nextA--;

            result = min(result, nextA+pastB);

            if(s[i] == 'b') pastB++;
        }

        return result;
    }
};