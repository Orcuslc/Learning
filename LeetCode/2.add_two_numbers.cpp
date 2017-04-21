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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        ListNode* p1 = l1, * p2 = l2;
        while(p1) {
            len1++;
            p1 = p1->next;
        }
        while(p2) {
            len2++;
            p2 = p2->next;
        }
        if(len1 < len2) return addTwoNumbers_ordered(l2, l1);
        else return addTwoNumbers_ordered(l1, l2);
    }
private:
    ListNode* addTwoNumbers_ordered(ListNode* l1, ListNode* l2) { // L1 is longer or equal to L2;
        int carry = 0, sum;
        ListNode* p = l1;
        while(l1) {
            sum = l1->val + (l2?l2->val:0) + carry;
            l1->val = sum%10;
            carry = sum/10;
            if(carry && !l1->next) {
                ListNode* h = new ListNode(carry);
                l1->next = h;
                l1 = l1->next;
            }
            l1 = l1->next;
            l2 = l2?l2->next:l2;
        }
        // if(carry) {
        //     ListNode h(carry);
        //     l1->next = &h;
        // }
        return p;
    }
};