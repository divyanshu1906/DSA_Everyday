class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        int idx = s.size()-1;

        while(idx >= 0 && s[idx] == ' ') idx--;
        
        while(idx >=0){
            string temp = "";
            while(idx >= 0 && s[idx] != ' '){
                temp.push_back(s[idx]);
                idx--;
            }

            reverse(temp.begin(), temp.end());

            if(!ans.empty() && !temp.empty()){
                ans += " ";
                ans += temp;
            }
            else if(ans.empty() && !temp.empty()){
                ans += temp;
            }
            idx--;
        }

        return ans;
    }
};