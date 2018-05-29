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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int h = getHeight(root), res = 0;
        while(root) {
            if(getHeight(root->right) == h-1) {
                res += (1<<(h-1));
                root = root->right;
            }
            else {
                res += (1<<(h-2));
                root = root->left;
            }
            h--;
        }
        return res;
    }
    
    int getHeight(TreeNode* root) { // O(log n) for complete trees;
        return !root? 0 : getHeight(root->left)+1;
    }
};