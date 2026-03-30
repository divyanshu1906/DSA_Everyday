class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<int, int> oddString, evenString;

        for(int i=0; i<s1.size(); i++){
            if(i%2==0){
                evenString[s1[i] - 'a']++;
                evenString[s2[i] - 'a']--;
            }
            else{
                oddString[s1[i] - 'a']++;
                oddString[s2[i] - 'a']--;
            }
        }

        for(auto &it : oddString){
            if(it.second > 0) return false;
        }

        for(auto &it : evenString){
            if(it.second > 0) return false;
        }

        return true;
    }
};