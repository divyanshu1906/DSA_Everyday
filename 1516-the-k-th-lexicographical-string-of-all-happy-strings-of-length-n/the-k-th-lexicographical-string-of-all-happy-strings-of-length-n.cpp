class Solution {
public:
    void generatingLexicographicalString(int n, vector<string>&lexicographicalString, vector<char> &character, string &str ){
        if(str.size()==n){
            lexicographicalString.push_back(str);
            return;
        } 
        for(int i=0; i<character.size(); i++){
            if(str.empty()){
                str += character[i];
                generatingLexicographicalString(n, lexicographicalString, character, str);
                str.pop_back();
            }
            else{
                if(character[i] != str.back()){
                    str += character[i];
                    generatingLexicographicalString(n, lexicographicalString, character, str);
                    str.pop_back();
                }
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>lexicographicalString;
        vector<char> character = {'a', 'b', 'c'};
        string str = "";
        generatingLexicographicalString(n, lexicographicalString, character, str);
        return k > lexicographicalString.size() ? "" : lexicographicalString[k-1];
    }
};