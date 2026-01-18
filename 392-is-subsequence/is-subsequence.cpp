class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n > m) return false;

        int i=0;
        for(int j=0; j<m; j++){
            if(s[i] == t[j]) i++;
            if(i >= n) break;
        }

        return i>=n ? true : false;
    }
};