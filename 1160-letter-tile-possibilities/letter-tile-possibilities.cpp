class Solution {
public:
    void recursion(int idx, string &str, string tiles, unordered_set<string>&st, vector<bool>&used){
        if(!str.empty()){
            st.insert(str);
        }
        for(int i=0; i<tiles.size(); i++){
            if(!used[i]){
                used[i] = true;
                str += tiles[i];
                recursion(i, str, tiles, st, used);
                str.pop_back();
                used[i] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_set<string>st;
        string str = "";
        vector<bool>used(n, false);
        recursion(0, str, tiles, st, used);
        return st.size();
    }
};