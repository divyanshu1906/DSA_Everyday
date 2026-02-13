class Solution {
public:
    int helper(string &s, char ch1, char ch2){
        int n = s.size();

        unordered_map<int, int>mpp;

        int count1 = 0, count2=0;
        int maxL = 0;
        for(int i=0; i<n; i++){
            if(s[i] != ch1 && s[i] != ch2){
                mpp.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }

            if(s[i] == ch1) count1++;
            if(s[i] == ch2) count2++;

            if(count1 == count2){
                maxL = max(maxL, count1+count2);
            }

            int diff = count1-count2;

            if(mpp.find(diff) != mpp.end()){
                maxL = max(maxL, i - mpp[diff]);
            }
            else mpp[diff] = i;
        }

        return maxL;
    }
    int longestBalanced(string s) {
        int n = s.size();

        int maxL = 0;

        int currCount = 1;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                currCount++;
            }
            else{
                maxL = max(maxL, currCount);
                currCount = 1;
            }
        }
        maxL = max(maxL, currCount);

        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'b', 'c'));

        int countA = 0, countB = 0, countC = 0;
        unordered_map<string, int>mpp;

        for(int i=0; i<n; i++){
            if(s[i] == 'a') countA++;
            if(s[i] == 'b') countB++;
            if(s[i] == 'c') countC++;

            if(countA == countB && countA == countC){
                maxL = max(maxL, countA*3);
            }

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            string key = to_string(diffAB) + "_" + to_string(diffAC);

            if(mpp.find(key) != mpp.end()){
                maxL = max(maxL, i - mpp[key]);
            }
            else mpp[key] = i;
        }

        return maxL;
    }
};