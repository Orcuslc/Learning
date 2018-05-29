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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int depth = getDepth(root->left)+getDepth(root->right);
        return max(depth, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    
    int getDepth(TreeNode* root) {
        if(!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};