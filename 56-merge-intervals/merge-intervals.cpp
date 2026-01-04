class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});

        for(int i=1; i<n; i++){
            vector<int>prev = ans.back();
            vector<int>curr = intervals[i];
            
            int prevFirst  = prev[0];
            int prevSecond = prev[1];
            int currFirst  = curr[0];
            int currSecond = curr[1];

            if(currFirst <= prevSecond){
                ans.pop_back();

                int newSecond = max(prevSecond, currSecond);
                ans.push_back({prevFirst, newSecond});

            }
            else{
                ans.push_back({currFirst, currSecond});
            }
        }

        return ans;
    }
};