class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;
        for(auto &o : obstacles){
            st.insert({o[0], o[1]});
        }

        int x = 0, y = 0;
        int dir = 0;
        int maxDist = 0;

        vector<vector<int>> directions{{0,1}, {1,0}, {0,-1}, {-1, 0}};
        
        for(int cmd : commands){
            if(cmd == -1){
                dir = (dir + 1) % 4;
            }
            else if(cmd == -2){
                dir = (dir - 1 + 4) % 4;
            }
            else{
                for(int k = 0; k < cmd; k++){
                    int nx = x + directions[dir][0];
                    int ny = y + directions[dir][1];

                    if(st.count({nx, ny})) break;

                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};