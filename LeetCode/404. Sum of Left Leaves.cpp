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
    int sumOfLeftLeaves(TreeNode* root) {
        return recursion(root, false);
    }
    
    int recursion(TreeNode* root, bool isleft) {
        if(!root) return 0;
        if(!root->left && !root->right) return isleft? root->val : 0;
        return recursion(root->left, true) + recursion(root->right, false);
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> left, right; right.push(root);
        int res = 0;
        while(!left.empty() || !right.empty()) {
            int size1 = left.size(), size2 = right.size();
            while(size1--) {
                TreeNode* now = left.front(); left.pop();
                if(!now->left && !now->right) res += now->val;
                if(now->left) left.push(now->left);
                if(now->right) right.push(now->right);
            }
            while(size2--) {
                TreeNode* now = right.front(); right.pop();
                if(now->left) left.push(now->left);
                if(now->right) right.push(now->right);
            }
        }
        return res;
    }
};