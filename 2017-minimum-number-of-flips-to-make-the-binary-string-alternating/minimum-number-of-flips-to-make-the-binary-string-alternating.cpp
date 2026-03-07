class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int i = 0, j=0;
        int flip1 = 0, flip2 = 0;

        int result = INT_MAX;

        while(j<2*n){
            char expectedChar1 = (j%2==0 ? '1' : '0');
            char expectedChar2 = (j%2==0 ? '0' : '1');

            if(s[j%n] != expectedChar1) flip1++;
            if(s[j%n] != expectedChar2) flip2++;

            if(j-i+1 > n){
                expectedChar1 = (i%2==0 ? '1' : '0');
                expectedChar2 = (i%2==0 ? '0' : '1');
                
                if(s[i%n] != expectedChar1) flip1--;
                if(s[i%n] != expectedChar2) flip2--;
                i++;
            }

            if(j-i+1 == n){
                result = min({result, flip1, flip2});
            }

            j++;
        }

        return result;
    }
};