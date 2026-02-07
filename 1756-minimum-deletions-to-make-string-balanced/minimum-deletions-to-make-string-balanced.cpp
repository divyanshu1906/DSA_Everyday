class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int>pastB(n, 0), nextA(n,0);

        for(int i=1; i<n; i++){
            pastB[i] += pastB[i-1];
            if(s[i-1] == 'b'){
                pastB[i]++;
            }
        }

        for(int i=n-2; i>=0; i--){
            nextA[i] += nextA[i+1];
            if(s[i+1] == 'a'){
                nextA[i]++;
            }
        }

        int result = INT_MAX;
        for(int i=0; i<n; i++){
            result = min(result, nextA[i]+pastB[i]);
        }

        return result;
    }
};