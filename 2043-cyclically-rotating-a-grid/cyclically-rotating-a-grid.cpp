class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int startRow = 0;
        int endRow   = m-1;

        int startCol = 0;
        int endCol   = n-1;

        while(startRow < endRow && startCol < endCol){

            int rows = endRow - startRow + 1;
            int cols = endCol - startCol + 1;

            int perimeter = 2 * (rows + cols) - 4;

            int rotate = k % perimeter;
        
            while(rotate>0){

                int floater = grid[startRow][endCol];
                for(int col = endCol-1; col>=startCol; col--){
                    int newFloater = grid[startRow][col];
                    grid[startRow][col] = floater;
                    floater = newFloater;
                }
                for(int row=startRow+1; row<=endRow; row++){
                    int newFloater = grid[row][startCol];
                    grid[row][startCol] = floater;
                    floater = newFloater;
                }
                for(int col=startCol+1; col<=endCol; col++){
                    int newFloater = grid[endRow][col];
                    grid[endRow][col] = floater;
                    floater = newFloater;
                }
                for(int row=endRow-1; row>=startRow; row--){
                    int newFloater = grid[row][endCol];
                    grid[row][endCol] = floater;
                    floater = newFloater;
                }

                rotate--;
            }

            startRow++;
            startCol++;
            endCol--;
            endRow--;
        }

        return grid;
    }
};