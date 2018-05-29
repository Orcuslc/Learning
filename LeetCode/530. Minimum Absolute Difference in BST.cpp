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
    int getMinimumDifference(TreeNode* root) {
        int prodecessor = INT_MIN, diff = INT_MAX;
        traversal(root, prodecessor, diff);
        return diff;
    }
    
    void traversal(TreeNode* root, int& prodecessor, int& diff) {
        if(root->left) traversal(root->left, prodecessor, diff);
        if(prodecessor != INT_MIN) diff = min(diff, abs(prodecessor - root->val));
        prodecessor = root->val;
        if(root->right) traversal(root->right, prodecessor, diff);
    }
};