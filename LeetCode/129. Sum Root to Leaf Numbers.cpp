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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int val) {
        if(!root->left && !root->right) {
            return val*10 + root->val;
        }
        int x = 0;
        if(root->left) {
            x += dfs(root->left, val*10+root->val);
        }
        if(root->right) {
            x += dfs(root->right, val*10+root->val);
        }
        return x;
    }
};