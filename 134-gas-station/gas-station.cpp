class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        vector<int>startingPoint;
        for(int i=0; i<n; i++){
            if(gas[i] >= cost[i]){
                startingPoint.push_back(i);
            }
        }

        if(startingPoint.empty()) return -1;

        int ans = -1;

        int m = startingPoint.size();
        for(int i=0; i<m; i++){
            int idx = startingPoint[i];

            int currGas = gas[idx];
            int currCost = cost[idx];

            int totalGas = currGas - currCost;
            int start = (idx + 1) % n;

            while(start != idx && totalGas > 0){
                int currGas = gas[start];
                int currCost = cost[start];

                totalGas = totalGas + currGas - currCost;

                start = (start + 1) % n;
            }

            if(start == idx && totalGas >= 0){
                ans = idx;
                break;
            }
        }

        return ans; 
    }
};