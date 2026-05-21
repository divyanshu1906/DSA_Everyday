class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        int ans = 0;

        unordered_set<string>st;
        for(int i=0; i<n; i++){
            string numStr = to_string(arr1[i]);

            string str = "";
            for(int j=0; j<numStr.size(); j++){
                str += numStr[j];
                st.insert(str);
            }
        }

        for(int i=0; i<m; i++){
            string numStr = to_string(arr2[i]);

            string str = "";
            for(int j=0; j<numStr.size(); j++){
                str += numStr[j];

                if(st.count(str) != 0){
                    ans = max(ans, (int)str.size());
                }
            }
        }

        return ans;
    }
};