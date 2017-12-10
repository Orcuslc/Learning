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
    int maxPathSum(TreeNode* root) {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }
    
    pair<int, int> dfs(TreeNode* root) {
        // first: 以root为一个端点; second: 反之;
        if(!root) return pair<int, int>(INT_MIN, INT_MIN);
        pair<int, int> left = dfs(root->left), right = dfs(root->right);
        pair<int, int> res;
        if(left.first < 0 && right.first < 0) res.first = root->val;
        else if(left.first < 0) res.first = root->val+right.first;
        else if(right.first < 0) res.first = root->val+left.first;
        else res.first = max(left.first, right.first)+root->val;
        
        // 没有子节点, 没有左子节点, 没有右子节点, 两个子节点都有;
        if(left.second == INT_MIN && right.second == INT_MIN && left.first == INT_MIN && right.first == INT_MIN) res.second = INT_MIN;
        else if(left.second == INT_MIN && left.first == INT_MIN) res.second = max(right.second, right.first);
        else if(right.second == INT_MIN && right.first == INT_MIN) res.second = max(left.second, left.first);
        else res.second = max(max(max(left.second, right.second), max(left.first, right.first)), left.first+root->val+right.first);
        return res;
    }
};