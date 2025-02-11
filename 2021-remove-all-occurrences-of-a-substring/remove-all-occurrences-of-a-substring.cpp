class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        int i = 0;
        while(i<s.size()){
            for(; i<s.size(); i++){
                int second = 0;
                int idx = i;
                while(second < m){
                    if(s[idx] != part[second]) break;
                    else second++, idx++;
                }
                if(second == m) {
                    s.erase(i, m);
                    i=0;
                    break;
                }
            }
        }
        return s;
    }
};