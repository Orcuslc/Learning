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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* now = root;
        while(now || !s.empty()) {
            if(now) {
                s.push(now);
                now = now->left;
            }
            else {
                now = s.top(); s.pop();
                res.push_back(now->val);
                now = now->right;
            }
        }
        return res;
    }
};