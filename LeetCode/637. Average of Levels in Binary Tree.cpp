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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            int size = q.size(); double sum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front(); q.pop();
                sum += (double)cur->val/(double)size;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(sum);
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
    vector<double> averageOfLevels(TreeNode* root) {
        int h = getHeight(root);
        vector<double> res(h, 0), count(h, 0);
        recursion(root, res, count, 0);
        for(int i = 0; i < h; i++) res[i] /= count[i];
        return res;
    }
    
    void recursion(TreeNode* root, vector<double>& res, vector<double>& count, int n) {
        if(!root) return;
        res[n] += root->val;
        count[n]++;
        recursion(root->left, res, count, n+1);
        recursion(root->right, res, count, n+1);
    }
    
    int getHeight(TreeNode* root) {
        if(!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};