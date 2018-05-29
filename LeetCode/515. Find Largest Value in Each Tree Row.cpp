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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q; q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            int largest = INT_MIN;
            for(int i = 0; i < size; i++) {
                TreeNode* s = q.front(); q.pop();
                largest = max(s->val, largest);
                if(s->left) q.push(s->left);
                if(s->right) q.push(s->right);
            }
            res.push_back(largest);
        }
        return res;
    }
};