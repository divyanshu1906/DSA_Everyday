class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0, r=0, maxLen=0, maxFre=0;
        vector<int>hash(26, 0);
        while(r<n){
            hash[s[r]-'A']++;
            maxFre = max(maxFre, hash[s[r]-'A']);
            while((r-l+1)-maxFre > k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxFre <= k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};