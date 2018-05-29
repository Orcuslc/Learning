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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* r = new TreeNode(v);
            r->left = root;
            return r;
        }
        queue<TreeNode*> q; q.push(root);
        while(--d > 1) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* s = q.front(); q.pop();
                if(s->left) q.push(s->left);
                if(s->right) q.push(s->right);
            }
        }
        while(!q.empty()) {
            TreeNode* r = q.front(); q.pop();
            TreeNode* left = new TreeNode(v);
            TreeNode* right = new TreeNode(v);
            if(r->left) left->left = r->left;
            if(r->right) right->right = r->right;
            r->left = left; r->right = right;
        }
        return root;
    }
};