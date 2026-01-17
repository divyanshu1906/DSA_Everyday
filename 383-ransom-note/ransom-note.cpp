class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>mpp;
        for(auto &ch : magazine){
            mpp[ch]++;
        }

        for(int i=0; i<ransomNote.size(); i++){
            if(mpp.find(ransomNote[i]) == mpp.end()) return false;

            if(--mpp[ransomNote[i]] == 0){
                mpp.erase(ransomNote[i]);
            }
        }

        return true;
    }
};