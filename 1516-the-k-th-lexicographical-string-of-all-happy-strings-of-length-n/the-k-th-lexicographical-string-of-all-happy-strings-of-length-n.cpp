class Solution {
public:
    void generatingLexicographicalString(int n, vector<string>&lexicographicalString, string &str ){
        if(str.size()==n){
            lexicographicalString.push_back(str);
            return;
        } 
        for(char ch='a'; ch<='c'; ch++){
            if(str.empty()){
                str += ch;
                generatingLexicographicalString(n, lexicographicalString, str);
                str.pop_back();
            }
            else{
                if(ch != str.back()){
                    str += ch;
                    generatingLexicographicalString(n, lexicographicalString, str);
                    str.pop_back();
                }
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>lexicographicalString;
        string str = "";
        generatingLexicographicalString(n, lexicographicalString, str);
        return k > lexicographicalString.size() ? "" : lexicographicalString[k-1];
    }
};