class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>>adj;

        for(auto &edge : edges){
            int u  = edge[0];
            int v  = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt*2});
        }

        vector<int>result(n, INT_MAX);
        result[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(node == n-1) return result[n-1];

            for(auto &it : adj[node]){
                int ngbr = it.first;
                int d    = it.second;

                if(dist + d < result[ngbr]){
                    result[ngbr] = dist + d;
                    pq.push({dist+d, ngbr});
                }
            }
        }

        return -1;
    }
};