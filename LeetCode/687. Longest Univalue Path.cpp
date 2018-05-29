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
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        vector<int> res = dfs(root);
        return max(res[0], res[1])-1;
    }
    
    vector<int> dfs(TreeNode* root) {
        if(!root) return vector<int>(2, 0);
        vector<int> res(2, 1);
        vector<int> left = dfs(root->left), right = dfs(root->right);
        if(root->left && root->right && root->val == root->left->val && root->val == root->right->val) {
            res[0] = max(left[0], right[0])+1;
            res[1] = max(max(left[1], right[1]), left[0]+right[0]+1);
        }
        else if(root->left && root->val == root->left->val) {
            res[0] = left[0]+1;
            res[1] = max(left[1], right[1]);
        }
        else if(root->right && root->val == root->right->val) {
            res[0] = right[0]+1;
            res[1] = max(left[1], right[1]);
        }
        else {
            res[0] = 1;
            res[1] = max(max(left[1], right[1]), max(left[0], right[0]));
        }
        return res;
    }
};