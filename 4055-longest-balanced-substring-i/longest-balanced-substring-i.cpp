class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();

        int result = 1;
        for(int i=0; i<n; i++){
            unordered_map<int, int>mpp;
            for(int j=i; j<n; j++){
                mpp[s[j]]++;

                int val = mpp[s[j]];

                bool allSame = true;
                for(auto &it : mpp){
                    if(it.second != val){
                        allSame = false;
                        break;
                    }
                }

                if(allSame){
                    result = max(result, j-i+1);
                }
            }
        }

        return result;
    }
};