class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        vector<long long> temp(n);
        for(int i = 0; i < n; i++) temp[i] = nums[i];

        vector<int> prevIdx(n), nextIdx(n);
        for(int i = 0; i < n; i++) {
            prevIdx[i] = i - 1;
            nextIdx[i] = i + 1;
        }

        long long badPairs = 0;
        set<pair<long long, int>> adjacentPairSum;

        for(int i = 0; i < n - 1; i++) {
            if(temp[i] > temp[i + 1]) badPairs++;
            adjacentPairSum.insert({temp[i] + temp[i + 1], i});
        }

        int operations = 0;

        while(badPairs > 0) {

            int first  = adjacentPairSum.begin()->second;
            int second = nextIdx[first];

            int leftFirst   = prevIdx[first];
            int rightSecond = nextIdx[second];

            adjacentPairSum.erase(adjacentPairSum.begin());

            if(temp[first] > temp[second]) badPairs--;

            if(leftFirst >= 0) {
                if(temp[leftFirst] > temp[first] &&
                   temp[leftFirst] <= temp[first] + temp[second]) {
                    badPairs--;
                }
                else if(temp[leftFirst] <= temp[first] &&
                        temp[leftFirst] > temp[first] + temp[second]) {
                    badPairs++;
                }
            }

            if(rightSecond < n) {
                if(temp[rightSecond] >= temp[second] &&
                   temp[rightSecond] < temp[first] + temp[second]) {
                    badPairs++;
                }
                else if(temp[rightSecond] < temp[second] &&
                        temp[rightSecond] >= temp[first] + temp[second]) {
                    badPairs--;
                }
            }

            if(leftFirst >= 0) {
                adjacentPairSum.erase({temp[leftFirst] + temp[first], leftFirst});
                adjacentPairSum.insert({temp[leftFirst] + temp[first] + temp[second], leftFirst});
            }

            if(rightSecond < n) {
                adjacentPairSum.erase({temp[second] + temp[rightSecond], second});
                adjacentPairSum.insert({temp[first] + temp[second] + temp[rightSecond], first});
                prevIdx[rightSecond] = first;
            }

            nextIdx[first] = rightSecond;
            temp[first] += temp[second];

            operations++;
        }

        return operations;
    }
};
