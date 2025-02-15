class Solution {
public:
    bool recursive(int i, int currSum, string s, int num){
        if(i==s.length()){
            return currSum==num;
        }
        if(currSum > num) return false;

        bool possible = false;
        for(int j=i; j<s.length(); j++){
            string str = s.substr(i, j-i+1);
            int val = stoi(str);
            possible = possible || recursive(j+1, currSum+val, s, num);
            if(possible){
                return true;
            }
        }
        return possible;
    }
    int punishmentNumber(int n) {
        int punish = 0;
        for(int num=1; num<=n; num++){
            int sq = num*num;
            string s = to_string(sq);
            if(recursive(0, 0, s, num)){
                punish += sq;
            }
        }
        return punish;
    }
};