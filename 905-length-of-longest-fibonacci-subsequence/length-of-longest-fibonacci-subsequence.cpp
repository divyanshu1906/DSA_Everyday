class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]] = i;
        }
        int maxLen = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int a = arr[i], b = arr[j];
                int len = 2;
                while(mpp.find(a+b) != mpp.end()){
                    int temp = a+b;
                    a = b;
                    b = temp;
                    len++;
                }
                if(len>2){
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen>2 ? maxLen : 0;
    }
};