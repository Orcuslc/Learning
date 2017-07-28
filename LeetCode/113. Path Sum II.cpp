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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if(!root) return res;
        dfs(res, vector<int>(), root, 0, sum);
        return res;
    }
    
    void dfs(vector<vector<int> >& res, vector<int> now, TreeNode* node, int nowSum, int& sum) {
        now.push_back(node->val);
        if(!node->left && !node->right) {
            if(nowSum + node->val == sum) res.push_back(now);
            return;
        }
        
        if(node->left) dfs(res, now, node->left, nowSum+node->val, sum);
        if(node->right) dfs(res, now, node->right, nowSum+node->val, sum);
    }
};