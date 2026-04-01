class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<pair<int, pair<int, char>>>robo;
        for(int i=0; i<n; i++){
            robo.push_back({positions[i], {healths[i], directions[i]}});
        }

        sort(robo.begin(), robo.end());

        stack<pair<int, pair<int, char>>>st;

        int idx = 0;
        while(idx < n && robo[idx].second.second == 'L'){
            st.push(robo[idx]);
            idx++;
        }

        while(idx < n && robo[idx].second.second == 'R'){
            st.push(robo[idx]);
            idx++;
        }

        while(idx < n){
            bool isBeaten = false;
            int collided = 0;

            while(!st.empty() && st.top().second.second == 'R' && robo[idx].second.second == 'L'){
                pair<int, pair<int, char>>P = st.top();
                st.pop();

                int prevHealth = P.second.first;
                int currHealth = robo[idx].second.first - collided;

                if(prevHealth > currHealth){
                    st.push({P.first, {prevHealth-1, P.second.second}});
                    isBeaten = true;
                    break;
                }
                else if(currHealth > prevHealth){
                    collided++;
                }
                else{
                    isBeaten = true;
                    break;
                }
            }
            if(!isBeaten){
                st.push({robo[idx].first, {robo[idx].second.first-collided, robo[idx].second.second}});
            }

            idx++;
        }

        unordered_map<int, int>mpp;
        while(!st.empty()){
            mpp[st.top().first] = st.top().second.first;
            st.pop();
        }

        vector<int>result;

        for(int i=0; i<n; i++){
            if(mpp.find(positions[i]) != mpp.end()){
                result.push_back(mpp[positions[i]]);
            }
        }

        return result;
    }
};