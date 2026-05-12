class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int sum = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(sum < tasks[i][1]) {

                int req = tasks[i][1] - sum;

                sum += req;
                ans += req;
            }

            sum -= tasks[i][0];
        }

        return ans;
    }
};