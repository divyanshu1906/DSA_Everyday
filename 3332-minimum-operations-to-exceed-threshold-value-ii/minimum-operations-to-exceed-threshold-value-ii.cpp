class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations= 0;
        priority_queue<long long , vector<long long >, greater<long long >>minHeap;
        int n = nums.size();
        for(int i=0; i<n; i++){
            minHeap.push(nums[i]);
        }
        while(minHeap.top() < k){
            long long  x = minHeap.top();
            minHeap.pop();
            long long  y = minHeap.top();
            minHeap.pop();
            long long newNum = min(x, y) * 2 + max(x, y);
            minHeap.push(newNum);
            operations++;
        }
        return operations;
    }
};