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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        n -= m;
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* pre = p;
        while(--m) pre = pre->next;
        ListNode* cur = pre->next;
        ListNode* nxt = cur->next;
        while(n--) {
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
            nxt = cur->next;
        }
        return p->next;
    }
};