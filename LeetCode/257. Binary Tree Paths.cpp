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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(!root) return paths;
        string path = to_string(root->val);
        dfs(paths, path, root);
        return paths;
    }
    
    void dfs(vector<string>& paths, string path, TreeNode* root) {
        if(!root->left && !root->right) {
            paths.push_back(path);
            return;
        }
        if(root->left) dfs(paths, path+"->"+to_string(root->left->val), root->left);
        if(root->right) dfs(paths, path+"->"+to_string(root->right->val), root->right);
    }
};