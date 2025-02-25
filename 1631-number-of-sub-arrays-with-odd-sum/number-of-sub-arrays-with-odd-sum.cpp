class Solution {
public:
    const int MOD = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>prevSum(n,0);
        prevSum[0]=arr[0];
        int ans = 0;
        for(int i=1; i<n; i++){
            prevSum[i] = prevSum[i-1]+arr[i];
        }
        int evenCount = 1;
        int oddCount = 0;
        for(int i=0; i<n; i++){
            if(prevSum[i]%2==0){
                ans = (ans+oddCount)%MOD;
                evenCount++;
            }
            else{
                ans =  (ans+evenCount)%MOD;
                oddCount++;
            }
        }
        return ans;
    }
};