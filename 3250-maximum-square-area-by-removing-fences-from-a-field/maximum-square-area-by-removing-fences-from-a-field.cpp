class Solution {
public:
    const int MOD = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        int h = hFences.size(), v = vFences.size();

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int>horizontalDiff;

        for(int i=0; i<h; i++){
            for(int j=i+1; j<h; j++){
                horizontalDiff.insert(hFences[j] - hFences[i]);
            }
        }

        unordered_set<int>verticalDiff;

        for(int i=0; i<v; i++){
            for(int j=i+1; j<v; j++){
                verticalDiff.insert(vFences[j] - vFences[i]);
            }
        }

        long long ans = INT_MIN;
        for(auto &it : horizontalDiff){
            if(verticalDiff.count(it) != 0){
                ans = max(ans, (long long)it);
            }
        }

        if(ans == INT_MIN) return -1;

        ans = (ans * ans) % MOD;
        return ans;
    }
};