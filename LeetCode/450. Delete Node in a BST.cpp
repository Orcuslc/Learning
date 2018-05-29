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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else {
            if(!root->left) return root->right;
            else if(!root->right) return root->left;
            TreeNode* prodecessor = root->left;
            while(prodecessor->right) prodecessor = prodecessor->right;
            root->val = prodecessor->val;
            root->left = deleteNode(root->left, prodecessor->val);
        }
        return root;
    }
};