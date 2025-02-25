class Solution {
public:
    const int MOD = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int evenCount = 1;
        int oddCount = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum%2==0){
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