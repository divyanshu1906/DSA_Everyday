/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        map<int, map<int, multiset<int>>>mpp; //{col : {row : val}}
        queue<pair<TreeNode*, pair<int, int>>>q;   //{root, {row, col}}
        q.push({root, {0, 0}});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();
                mpp[col][row].insert(node->val);
                if(node->left){
                    q.push({node->left, {row+1, col-1}});
                }
                if(node->right){
                    q.push({node->right, {row+1, col+1}});
                }
            }
        }
        for(auto &it : mpp){
            vector<int>temp;
            for(auto &var : it.second){
                temp.insert(temp.end(), var.second.begin(), var.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};