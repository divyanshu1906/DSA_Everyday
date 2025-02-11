class Solution {
public:
    int n;
    bool bfs(int node, vector<vector<int>>& graph, vector<bool>&visited, vector<int>&color){
        queue<int>q;
        q.push(node);
        visited[node] = true;
        color[node] = 0;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto &arr : graph[ele]){
                if(!visited[arr]){
                    q.push(arr);
                    visited[arr] = true;
                    color[arr] = 1 - color[ele];
                }
                else if(visited[arr] && color[ele] == color[arr]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vector<bool>visited(n, false);
        vector<int>color(n, -1);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(!bfs(i, graph, visited, color)) return false;
            }
        }
        return true;
    }
};