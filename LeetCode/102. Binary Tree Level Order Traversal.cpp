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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> now;
            for(int i = 0; i < size; i++) {
                TreeNode* s = q.front(); q.pop();
                now.push_back(s->val);
                if(s->left) q.push(s->left);
                if(s->right) q.push(s->right);
            }
            res.push_back(now);
        }
        return res;
    }
};