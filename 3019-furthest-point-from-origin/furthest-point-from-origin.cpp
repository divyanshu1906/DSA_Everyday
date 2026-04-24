class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftSide  = 0;
        int rightSide = 0;
        int dash      = 0;
        for(int i=0; i<moves.length(); i++){
            if(moves[i] == 'L') leftSide++;
            else if(moves[i] == 'R') rightSide++;
            else dash++;
        }

        return abs(leftSide - rightSide) + dash;
    }
};