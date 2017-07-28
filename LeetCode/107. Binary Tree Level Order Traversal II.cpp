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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
            res.insert(res.begin(), now);
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        int h = getHeight(root);
        vector<vector<int>> res(h, vector<int>{});
        dfs(res, root, h-1);
        return res;
    }
    
private:
    int getHeight(TreeNode* root) {
        if(!root) return 0;
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
    
    void dfs(vector<vector<int>>& res, TreeNode* r, int n) {
        if(!r) return;
        res[n].push_back(r->val);
        dfs(res, r->left, n-1);
        dfs(res, r->right, n-1);
    }
};