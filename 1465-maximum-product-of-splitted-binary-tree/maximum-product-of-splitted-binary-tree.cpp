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
    const int MOD = 1e9+7;
    long long dfs(TreeNode* root){
        if(root == NULL) return 0;

        root->val += dfs(root->left) + dfs(root->right);

        return root->val;
    }
    int maxProduct(TreeNode* root) {
        long long totalSum = dfs(root);

        queue<TreeNode*>q;
        q.push(root);

        long long ans = 0;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node==NULL) continue;

            long long curr = (totalSum - node->val) * node->val;
            ans = max((long long)ans, curr);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        ans = ans % MOD;

        return ans;
    }
};