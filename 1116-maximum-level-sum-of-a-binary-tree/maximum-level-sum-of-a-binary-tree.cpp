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
    void dfs(TreeNode* Node, int level, vector<int>&sum){
        if(Node == NULL) return;
        if(sum.size() == level) sum.push_back(Node->val);   
        else sum[level] += Node->val;

        dfs(Node->left, level+1, sum);
        dfs(Node->right, level+1, sum);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int>sum={INT_MIN};
        dfs(root, 1, sum);

        return max_element(sum.begin(), sum.end()) - sum.begin();
    }
};