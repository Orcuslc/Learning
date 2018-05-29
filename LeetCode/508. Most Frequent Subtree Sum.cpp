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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        traversal(root, mp);
        vector<int> res; int count = 0;
        for(auto p: mp) {
            if(p.second > count) {
                res.clear();
                res.push_back(p.first);
                count = p.second;
            }
            else if(p.second == count) res.push_back(p.first);
        }
        return res;
    }
    
    int traversal(TreeNode* root, unordered_map<int, int>& mp) {
        if(!root) return 0;
        int left = traversal(root->left, mp), right = traversal(root->right, mp);
        mp[left+right+root->val]++;
        return left + right + root->val;
    }
};