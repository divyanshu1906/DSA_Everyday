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
    bool findingSymmetric(TreeNode* leftNode, TreeNode* rightNode){
        if(leftNode == NULL && rightNode == NULL) return true;

        if((leftNode == NULL && rightNode != NULL) || (leftNode != NULL && rightNode == NULL)) return false;

        if(leftNode->val != rightNode->val) return false;

        bool firstHalf  = findingSymmetric(leftNode->left, rightNode->right);
        bool secondHalf = findingSymmetric(leftNode->right, rightNode->left);

        return firstHalf && secondHalf;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;

        return findingSymmetric(root->left, root->right);
    }
};