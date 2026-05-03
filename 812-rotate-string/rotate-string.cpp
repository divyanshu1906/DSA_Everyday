class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        string newStr = s + s;

        for(int i=0; i<newStr.size(); i++){
            int j=0;
            int k=i;

            while(j<goal.size() && goal[j] == newStr[k]){
                j++;
                k++;
            }

            if(j==goal.size()) return true;
        }

        return false;
    }
};