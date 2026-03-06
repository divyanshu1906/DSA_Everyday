class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();

        if(n == 1 && s[0] == '1') return true;

        bool foundSegment = false;
        for(int i=0; i<n; i++){
            if(s[i] == '1' && foundSegment) return false;
            while(i < n && s[i] == '1'){
                i++;
                foundSegment = true;
            }
        }

        return  foundSegment;
    }
};