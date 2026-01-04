class Solution {
public:
    vector<int>findingDivisors(int n){
        vector<int>divisors;
        divisors.push_back(1);
        divisors.push_back(n);
        for(int i=2; i*i<=n; i++){
            if(n%i == 0){
                int secondNum = n/i;
                if(secondNum != i){
                    divisors.push_back(secondNum);
                }
                divisors.push_back(i);
            }
        }

        return divisors;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int>mpp;

        for(auto &it : nums){
            mpp[it]++;
        }

        int sum = 0;
        for(auto &it : mpp){
            int num = it.first;
            int freq = it.second;
            vector<int>divisors = findingDivisors(num);

            int currSum = 0;
            if(divisors.size() == 4){
                for(int j=0; j<4; j++){
                    currSum += divisors[j];
                }
            }
            currSum = currSum * freq;
            sum += currSum;
        }

        return sum;
    }
};