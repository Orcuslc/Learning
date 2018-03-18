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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* t = q.front(); q.pop();
                if(i == size-1) res.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return res;
    }
};

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        int height = getHeight(root);
        vector<int> res(height, 0);
        dfs(res, root, 0);
        return res;
    }
    
    void dfs(vector<int>& res, TreeNode* r, int n) {
        if(!r) return;
        dfs(res, r->left, n+1);
        res[n] = r->val;
        dfs(res, r->right, n+1);
    }
    
    int getHeight(TreeNode* r) {
        if(!r) return 0;
        return max(getHeight(r->left), getHeight(r->right))+1;
    }
};