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
    void reorderList(ListNode* head) {
        while(head) {
            head->next = reverse(head->next);
            head = head->next;
        }
    }
    
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = NULL, *cur = head, *nex = head->next;
        while(cur) {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};