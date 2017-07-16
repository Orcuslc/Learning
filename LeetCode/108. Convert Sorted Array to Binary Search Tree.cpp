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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size()) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        vector<int> left(nums.begin(), nums.begin()+mid), right(nums.begin()+mid+1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursion(nums, 0, nums.size()-1);
    }
    
    TreeNode* recursion(vector<int>& nums, int left, int right) {
        if(right < left) return NULL;
        if(right == left) return new TreeNode(nums[left]);
        
        int mid = (right+left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = recursion(nums, left, mid-1);
        root->right = recursion(nums, mid+1, right);
        return root;
    }
};