class Solution {
public:
    void generatingLexicographicalString(int n, int &k, string &str, string&ans ){
        if(str.size()==n){
            k--;
            if(k==0){
                ans = str;
            }
            return;
        } 
        for(char ch='a'; ch<='c'; ch++){
            if(str.empty()){
                str += ch;
                generatingLexicographicalString(n, k, str, ans);
                str.pop_back();
            }
            else{
                if(ch != str.back()){
                    str += ch;
                    generatingLexicographicalString(n, k, str, ans);
                    str.pop_back();
                }
            }
        }
    }
    string getHappyString(int n, int k) {
        string str = "";
        string ans = "";
        generatingLexicographicalString(n, k, str, ans);
        return ans.empty() ? "": ans;
    }
};