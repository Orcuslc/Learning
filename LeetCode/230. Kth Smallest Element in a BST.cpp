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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        inorder(root, k, res);
        return res;
    }
    
    void inorder(TreeNode* root, int& k, int& res) {
        if(root->left) inorder(root->left, k, res);
        if(--k == 0) {
            res = root->val;
            return;
        }
        if(root->right) inorder(root->right, k, res);
    }
};