class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        bool carry = false;

        int m = a.size(), n = b.size();

        int i = m-1, j = n-1;

        while(i>=0 && j>=0){
            if(a[i] == '1' && b[j] == '1'){
                if(carry){
                    ans += '1';
                }
                else {
                    ans += '0';
                    carry = true;
                }
            }
            else if(a[i] == '1' && carry){
                ans += '0';
            }
            else if(b[j] == '1' && carry){
                ans += '0';
            }
            else if(carry){
                ans += '1';
                carry = false;
            }
            else{
                if(a[i] == '0' && b[j] == '0') ans += '0';
                else ans += '1';
            }
            i--;
            j--;
        }
        while(i>=0){
            if(a[i] == '1' && carry){
                ans += '0';
            }
            else if(carry){
                ans += '1';
                carry = false;
            }
            else ans += a[i];
            i--;
        }

        while(j>=0){
            if(b[j] == '1' && carry){
                ans += '0';
            }
            else if(carry){
                ans += '1';
                carry = false;
            }
            else ans += b[j];
            j--;
        }

        if(carry) ans += '1';

        reverse(ans.begin(), ans.end());

        return ans;
    }
};