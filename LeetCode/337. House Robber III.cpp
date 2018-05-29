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
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
    
    vector<int> dfs(TreeNode* root) {
        if(!root) return vector<int>(2, 0);
        vector<int> left = dfs(root->left), right = dfs(root->right);
        vector<int> res(2, 0);
        res[0] = left[1] + right[1] + root->val; // Rob this layer, which means Not rob the next layer;
        res[1] = max(left[0], left[1]) + max(right[0], right[1]); // Not rob this layer, but the next one;
        return res;
    }
};