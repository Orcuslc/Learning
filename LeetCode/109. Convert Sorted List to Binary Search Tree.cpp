/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        int length = 0; 
        while(p) {
            p = p->next;
            length++;   
        }
        return recursion(head, length);
    }
    
    TreeNode* recursion(ListNode* left, int length) {
        if(length <= 0) return NULL;
        if(length == 1) return new TreeNode(left->val);
        int mid = length/2;
        ListNode* p = left; for(int i = 0; i < mid; i++) p = p->next;
        TreeNode* root = new TreeNode(p->val);
        root->left = recursion(left, mid);
        root->right = recursion(p->next, length-mid-1);
        return root;
    }
};