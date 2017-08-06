/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* last = head, * p = head;
        int now = head->val; p = p->next;
        while(p) {
            while(p && p->val == now) p = p->next;
            if(!p) {
                last->next = p; return head;
            }
            last->next = p;
            last = p;
            now = p->val;
            p = p->next;
        }
        return head;
    }
};