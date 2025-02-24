class Solution {
public:
    unordered_map<int,vector<int>>adj;
    unordered_map<int, int>bobMap;
    int aliceIncome ;
    bool DFSBob(int curr, int t, vector<bool>&visited){
        visited[curr] = true;
        bobMap[curr] = t;

        if(curr==0){
            return true;
        }

        for(auto ngbr : adj[curr]){
            if(!visited[ngbr]){
                if(DFSBob(ngbr, t+1, visited)==true){
                    return true;
                }
            }
        }
        bobMap.erase(curr);
        return false;
    }
    void DFSAlice(int curr, int time, int income, vector<bool>&visited, vector<int>&amount){
        visited[curr] = true;
        if(bobMap.find(curr)==bobMap.end() || time < bobMap[curr]){
            income += amount[curr];
        }
        else if(time==bobMap[curr]){
            income += (amount[curr]/2);
        }

        if(adj[curr].size()==1 && curr!=0){
            aliceIncome = max(aliceIncome, income);
        }
        for(auto ngbr : adj[curr]){
            if(!visited[ngbr]){
                DFSAlice(ngbr, time+1, income, visited, amount);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();

        aliceIncome = INT_MIN;
        for(vector<int>&ed : edges){
            int u = ed[0];
            int v = ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int time = 0;
        vector<bool>visited(n, false);
        DFSBob(bob, time, visited);

        int income = 0;
        visited.assign(n, false);
        DFSAlice(0, 0, income, visited, amount);
        return aliceIncome;
    }
};