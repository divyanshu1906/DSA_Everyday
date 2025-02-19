class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> vec(3, 0);
        int n = bills.size();
        for(int i=0; i<n; i++){
            if(bills[i]==5){
                vec[0]++;
            }
            else if(bills[i]==10){
                if(vec[0]==0) return false;
                else{
                    vec[1]++;
                    vec[0]--;
                }
            }
            else{
                if(vec[0]==0 ) return false;
                if(vec[0]<3 && vec[1]==0) return false;
                else if(vec[1]!=0 && vec[0]>=1){
                    vec[1]--;
                    vec[0]--;
                    vec[2]++;
                }
                else{
                    vec[0] -= 3;
                    vec[2]++;
                }
            }
        }
        return true;
    }
};