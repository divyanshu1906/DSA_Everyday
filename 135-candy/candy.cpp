class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>distributedCandy(n);

        distributedCandy[0] = 1;
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                distributedCandy[i] = distributedCandy[i-1] + 1;
            }
            else {
                distributedCandy[i] = 1;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                distributedCandy[i] = max(distributedCandy[i], distributedCandy[i+1] + 1);
            }
        }

        int totalCandy = accumulate(distributedCandy.begin(), distributedCandy.end(), 0);

        return totalCandy;
    }
};