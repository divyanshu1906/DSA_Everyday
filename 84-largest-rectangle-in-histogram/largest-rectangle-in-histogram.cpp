class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>prevSmaller(n);
        prevSmaller[0] = -1;

        stack<int>st;
        st.push(0);

        for(int i=1; i<n; i++){

            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }

            if(st.empty()){
                prevSmaller[i] = -1;
            }
            else{
                prevSmaller[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<int>nextSmaller(n);
        nextSmaller[n-1] = n;

        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }

            if(st.empty()){
                nextSmaller[i] = n;
            }
            else{
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int prev = prevSmaller[i];
            int next = nextSmaller[i];

            int total = ((next - prev) - 1) * heights[i];

            ans = max(ans, total);
        }

        return ans;
    }
};