class Solution {
public:
    bool fun(int i, int j, string &s){

        if(i >= j) return true;

        if(!isalnum(s[i])){
            return fun(i+1, j, s);
        }
        else if(!isalnum(s[j])){
            return fun(i, j-1, s);
        }
        else{
            if(tolower(s[i]) != tolower(s[j])) return false;
        }
        return fun(i+1, j-1, s);
    }
    bool isPalindrome(string s) {
        return fun(0, s.size()-1, s);
    }
};