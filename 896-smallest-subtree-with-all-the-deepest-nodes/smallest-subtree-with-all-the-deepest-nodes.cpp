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
    void depth(TreeNode* root, int d, unordered_map<int, int>&mpp, int &maxD){
        if(!root) return;

        maxD = max(maxD, d);
        mpp[root->val] = d;

        depth(root->left,  d+1, mpp, maxD);
        depth(root->right, d+1, mpp, maxD);
    }

    TreeNode* LCA(TreeNode* root, unordered_map<int, int>&mpp, int maxD){
        if(!root || mpp[root->val] == maxD) return root;

        TreeNode* left  = LCA(root->left,  mpp, maxD);
        TreeNode* right = LCA(root->right, mpp, maxD);

        if(left && right) return root;

        return left != NULL ? left : right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<int, int>mpp;
        int maxD = 0;

        depth(root, 0, mpp, maxD);

        return LCA(root, mpp, maxD);
    }
};