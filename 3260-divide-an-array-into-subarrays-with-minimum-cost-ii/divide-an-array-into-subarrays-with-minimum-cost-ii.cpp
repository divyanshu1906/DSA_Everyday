class Solution {
public:
    typedef long long ll;
    typedef pair<long long, int>P;

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        set<P>smallestK, remaining;

        int i = 1;
        ll sum = 0;

        while(i - dist < 1){
            sum += nums[i];
            smallestK.insert({nums[i], i});

            if(smallestK.size() > k-1){
                P last = *smallestK.rbegin();
                sum -= last.first;

                remaining.insert(last);
                smallestK.erase(last);
            }
            i++;
        }

        ll result = LLONG_MAX;

        while(i<n){
            sum += nums[i];
            smallestK.insert({nums[i], i});

            if(smallestK.size() > k-1){
                P last = *smallestK.rbegin();
                sum -= last.first;

                remaining.insert(last);
                smallestK.erase(last);
            }

            result = min(result, sum);

            P remove = {nums[i-dist], i-dist};

            if(smallestK.count(remove)){
                smallestK.erase(remove);
                sum -= remove.first;

                if(!remaining.empty()){
                    P temp = *remaining.begin();
                    sum += temp.first;
                    smallestK.insert(temp);
                    remaining.erase(temp);
                }
            }
            else{
                remaining.erase(remove);
            }
            i++;
        }

        return nums[0] + result;
    }
};