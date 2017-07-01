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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        bool res = false;
        dfs(root, 0, sum, res);
        return res;
    }
    
    void dfs(TreeNode* root, int now, int sum, bool& res) {
        if(!root->left && !root->right) {
            now += root->val;
            if(now == sum) {
                res = true;
                return;
            }
        }
        if(root->left) dfs(root->left, now+root->val, sum, res);
        if(root->right) dfs(root->right, now+root->val, sum, res);
    }
};