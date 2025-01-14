class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int>mpp;
        int i=0;
        for(int j=0; j<n; j++){
            char ch = s[j];
            mpp[ch]++;
            while(mpp[ch]>1){
                mpp[s[i]]--;
                if(mpp[s[i]]==0) mpp.erase(s[i]);
                    i++;
            }
            ans = max(ans, j-i+1);
        } 
        return ans;
    }
};