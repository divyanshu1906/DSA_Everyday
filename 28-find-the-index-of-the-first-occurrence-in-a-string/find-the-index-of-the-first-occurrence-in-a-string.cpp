class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0, j=0;
        int n = haystack.size();
        int m = needle.size();

        for(int i=0; i<n; i++){
            if(haystack[i] == needle[0]){
                string remString = haystack.substr(i, m);

                if(remString == needle) return i;
            }
        }

        return -1;
    }
};