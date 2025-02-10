class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++){
            if(!isalpha(s[i])){
                if(!ans.empty()){
                    ans.pop_back();
                }
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};