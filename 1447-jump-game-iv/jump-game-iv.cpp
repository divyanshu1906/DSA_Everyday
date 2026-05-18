class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>>eleIdx;
        for(int i=0; i<n; i++){
            eleIdx[arr[i]].push_back(i);
        }

        vector<bool>visited(n, false);
        queue<pair<int, int>>q;
        q.push({0, 0});
        visited[0] = true;

        while(!q.empty()){
            auto [idx, step] = q.front();
            q.pop();

            if(idx == n-1) return step;

            if(idx-1 >= 0 && !visited[idx-1]){
                q.push({idx-1, step+1});
                visited[idx-1] = true;
            }

            if(idx+1 < n && !visited[idx+1]){
                q.push({idx+1, step+1});
                visited[idx+1] = true;
            }

            for(auto &nextIdx : eleIdx[arr[idx]]){
                if(!visited[nextIdx]) {
                    visited[nextIdx] = true;
                    q.push({nextIdx, step + 1});
                }
            }

            eleIdx[arr[idx]].clear();
        }

        return -1;
    }
};