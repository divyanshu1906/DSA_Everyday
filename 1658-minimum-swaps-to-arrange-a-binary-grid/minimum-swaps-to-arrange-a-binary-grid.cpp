class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int>rowZeroCount(n,0);

        for(int i=0; i<n; i++){
            int continuousZero = 0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j] == 1) break;
                continuousZero++;
            }
            rowZeroCount[i] = continuousZero;
        }

        int swaps = 0;

        for(int i=0;i<n;i++){
            int required = n-i-1;

            int j=i;
            while(j<n && rowZeroCount[j] < required){
                j++;
            }

            if(j==n) return -1;

            while(j>i){
                swaps++;
                swap(rowZeroCount[j], rowZeroCount[j-1]);
                j--;
            }
        }

        return swaps;
    }
};