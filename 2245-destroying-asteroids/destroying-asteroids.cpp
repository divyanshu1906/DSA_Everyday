class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());

        long long masses = mass;

        for(int i=0; i<n; i++){
            if(masses < asteroids[i]){
                return false;
            }

            masses += (long long)asteroids[i];
        }

        return true;
    }
};