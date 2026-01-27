class Solution {
public:
    bool check(int row, int col, vector<vector<char>>&grid, vector<vector<bool>>&visited){
        int n = grid.size();
        int m = grid[0].size();

        if((row >= 0 && row < n) && (col >= 0 && col < m) && grid[row][col] == '1' && !visited[row][col]) return true;

        return false;
    }
    void bfs(int i, int j, vector<vector<char>>&grid, vector<vector<bool>>&visited, vector<vector<int>>&directions){
        visited[i][j] = true;

        queue<pair<int, int>>q;
        q.push({i, j});

        while(!q.empty()){
            pair<int, int>P = q.front();
            q.pop();

            int i_ = P.first;
            int j_ = P.second;

            for(auto &dir : directions){
                int row = dir[0] + i_;
                int col = dir[1] + j_;

                if(check(row, col, grid, visited)){
                    q.push({row, col});
                    visited[row][col] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n, vector<bool>(m, false));
        vector<vector<int>>directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int islands = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i, j, grid, visited, directions);
                    islands++;
                }
            }
        }

        return islands;
    }
};