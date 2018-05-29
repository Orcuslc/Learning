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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int maxCount = 0, curCount = 0, mode = 0;
        inorder(root, res, maxCount, mode, curCount);
        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& res, int& maxCount, int& mode, int& curCount) {
        // cout << mode << endl;
        if(!root) return;
        inorder(root->left, res, maxCount, mode, curCount);
        if(maxCount == 0) {
            mode = root->val; curCount = maxCount = 1;
            res.push_back(mode);
        }
        else {
            if(root->val == mode) {
                curCount++;
            }
            else {
                mode = root->val;
                curCount = 1;
            }
            if(curCount == maxCount) res.push_back(mode);
            else if(curCount > maxCount) {
                res.clear(); 
                res.push_back(mode);
                maxCount = curCount;
            }
        }
        inorder(root->right, res, maxCount, mode, curCount);
    }
};