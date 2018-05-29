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
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        recursive(root, res);
        return res;
    }
    
    int recursive(TreeNode* root, int& res) {
        if(!root) return 0;
        int left = recursive(root->left, res), right = recursive(root->right, res);
        res += abs(left-right);
        return left+right+root->val;
    }
};