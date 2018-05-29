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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode* p1 = head, * p2 = head; int n = 0;
        while(p1) {
            p1 = p1->next; n++;
        }
        k = k%n;
        if(k == 0) return head;
        p1 = head;
        while(k--) p1 = p1->next;
        while(p1->next) {
            p1 = p1->next; p2 = p2->next;
        }
        p1->next = head;
        ListNode* res = p2->next;
        p2->next = NULL;
        return res;
    }
};