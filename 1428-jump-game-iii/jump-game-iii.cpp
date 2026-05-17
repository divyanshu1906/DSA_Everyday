class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int>q;
        q.push(start);

        vector<bool>visited(n, false);
        visited[start] = true;

        while(!q.empty()){
            int idx = q.front();
            q.pop();

            if(arr[idx] == 0) return true;

            int prev = idx - arr[idx];
            int next = idx + arr[idx];

            if(prev >= 0 && !visited[prev]){
                q.push(prev);
                visited[prev] = true;
            }
            if(next < n && !visited[next]){
                q.push(next);
                visited[next] = true;
            } 
        }

        return false;
    }
};