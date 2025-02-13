class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations= 0;
        priority_queue<long long int , vector<long long int>, greater<long long int>>minHeap;
        int n = nums.size();
        for(int i=0; i<n; i++){
            minHeap.push(nums[i]);
        }
        while(minHeap.top() < k){
            long long int x = minHeap.top();
            minHeap.pop();
            long long int y = minHeap.top();
            minHeap.pop();
            long long int newNum = min(x, y) * 2 + max(x, y);
            minHeap.push(newNum);
            operations++;
        }
        return operations;
    }
};