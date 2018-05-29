/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return pathSumStartWith(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int pathSumStartWith(TreeNode* root, int sum) {
        if(!root) return 0;
        return (root->val == sum? 1:0) + pathSumStartWith(root->left, sum-root->val) + pathSumStartWith(root->right, sum-root->val);
    }
};