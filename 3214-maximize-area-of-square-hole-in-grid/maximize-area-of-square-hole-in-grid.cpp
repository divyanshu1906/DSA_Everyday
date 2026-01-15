class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hSize = hBars.size();
        int vSize = vBars.size();

        if(hSize == 0 || vSize == 0) return 1;

        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int continuous1 = 1, continuous2 = 1;
        int maxConti1 = 1, maxConti2=1;

        for(int i=1; i<hSize; i++){
            if(hBars[i-1] + 1 != hBars[i]){
                
                continuous1 = 1;
            }
            else continuous1++;
            maxConti1 = max(maxConti1, continuous1);
        }

        for(int i=1; i<vSize; i++){
            if(vBars[i-1] + 1 != vBars[i]){
                continuous2 = 1;
            }
            else continuous2++;
            maxConti2 = max(maxConti2, continuous2);
        }

        int ans = min(maxConti2 + 1, maxConti1 + 1);

        return ans * ans;
    }
};