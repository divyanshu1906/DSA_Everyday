class Solution {
public:
    int mirrorDistance(int n) {
        string numStr = to_string(n);
        reverse(numStr.begin(), numStr.end());

        int num = stoi(numStr);

        return abs(num-n);
    }
};