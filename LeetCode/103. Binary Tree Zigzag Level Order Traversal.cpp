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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        // queue<TreeNode*> q1; q1.push(root);
        stack<TreeNode*> q1, q2; q1.push(root);
        int flag = 0;
        
        while(!q1.empty() || !q2.empty()) {
            vector<int> now;
            if(flag == 0) {
                int size = q1.size();
                for(int i = 0; i < size; i++) {
                    TreeNode* s = q1.top(); q1.pop();
                    now.push_back(s->val);
                    if(s->left) q2.push(s->left);
                    if(s->right) q2.push(s->right);
                }
                flag = 1;
            }
            else {
                int size = q2.size();
                for(int i = 0; i < size; i++) {
                    TreeNode* s = q2.top(); q2.pop();
                    now.push_back(s->val);
                    if(s->right) q1.push(s->right);
                    if(s->left) q1.push(s->left);
                }
                flag = 0;
            }
            res.push_back(now);
        }
        return res;
    }
};