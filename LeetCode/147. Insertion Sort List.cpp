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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* nul = new ListNode(0); nul->next = head;
        ListNode* cur = head, * pre = nul;
        while(cur) {
            if(cur->next && cur->next->val < cur->val) {
                while(pre->next && pre->next->val < cur->next->val) {
                    pre = pre->next;
                }
                ListNode* pos = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = pos;
                pre = nul;
            }
            else cur = cur->next;
        }
        ListNode* res = nul->next;
        delete nul;
        return res;
    }
};