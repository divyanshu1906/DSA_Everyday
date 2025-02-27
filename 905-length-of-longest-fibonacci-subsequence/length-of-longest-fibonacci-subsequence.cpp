class Solution {
public:
    int solve(int i, int j, vector<int>&arr, unordered_map<int, int>&mpp){
        int sum = arr[j] - arr[i];
        if(mpp.count(sum) && mpp[sum] < i){
            int k = mpp[sum];
            return 1 + solve(k, i, arr, mpp);
        }
        return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]] = i;
        }
        int maxLen = 0;
        for(int i=1; i<n; i++){
            for(int j=i+1; j<n; j++){
                int length = solve(i, j, arr, mpp);
                if(length>2){
                    maxLen = max(maxLen, length);
                }
            }
        }
        return maxLen;
    }
};