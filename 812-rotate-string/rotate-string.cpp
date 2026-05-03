class Solution {
public:
    vector<int>lpsBuilder(string &goal){
        int n = goal.size();
        vector<int>lps(n, 0);
        int i=1;
        int length = 0;

        while(i<n){
            if(goal[i] == goal[length]){
                length++;
                lps[i] = length;
                i++;
            }
            else {
                if(length != 0){
                    length = lps[length-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        vector<int>lps = lpsBuilder(goal);

        string newS = s+s;
        int n = newS.size();
        int m = goal.size();

        int i=0, j=0;

        while(i<n && j<m){
            bool flag = false;
            if(newS[i] == goal[j]){
                j++;
                i++;
            }
            else if(j!=0){
                j = lps[j-1];
                flag = true;
            }
            else{
                j=0;
                i++;
            }
        }

        if(j==m) return true;
        
        return false;
    }

};