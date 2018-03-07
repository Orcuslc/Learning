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
    ListNode* partition(ListNode* head, int x) {
        ListNode n1(0), n2(0);
        ListNode* p1 = &n1, *p2 = &n2;
        while(head) {
            if(head->val < x) {
                p1->next = head;
                p1 = p1->next;
            }
            else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = n2.next;
        return n1.next;
    }
};