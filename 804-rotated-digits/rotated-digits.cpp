class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for(int i=1; i<=n; i++){
            string numStr = to_string(i);

            bool isPossible = true;
            bool isChange   = false;
            for(int j=0; j<numStr.length(); j++){
                if(numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '7'){
                    isPossible = false;
                    break;
                }
                if(numStr[j] == '2' || numStr[j] == '5' || numStr[j] == '6' || numStr[j] == '9'){
                    isChange = true;
                }
            }
            if(isPossible && isChange){
                ans++;
            }
        }

        return ans;
    }
};