class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();

        int x2 = x+k-1;
        int y2 = y+k-1;

        while(x < x2){
            for(int col = y; col<=y2; col++){
                swap(grid[x][col], grid[x2][col]);
            }
            x++;
            x2--;
        }

        return grid;
    }
};