class Solution {
public:
    int binaryGap(int n) {
        int result = 0;

        int lastOne = -1;
        for(int i=0; i<32; i++){
            int bit = (n>>i) & 1;

            if(bit == 1 && lastOne == -1){
                lastOne = i;
            }
            else if(bit == 1 && lastOne != -1){
                result = max(result, i-lastOne);
                lastOne = i;
            }
        }

        return result;
    }
};