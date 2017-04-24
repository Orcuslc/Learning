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
        vector<ListNode*> s1, s2;
        int sum = 0, carry = 0, n1 = 0, n2 = 0;
        ListNode* p;
        while(l1) {
            s1.push(l1);
            l1 = l1->next;
            n1++;
        }
        while(l2) {
            s2.push(l2);
            l2 = l2->next;
            n2++;
        }
        if(n1 >= n2) { // l1 is longer than l2, so add l2 to l1;
            while(!s2.empty()) {
                p = s1.top();
                sum = p->val + s2.top()->val + carry;
                p->val = sum%10;
                carry = sum/10;
                s1.pop();
                s2.pop();
            }
            while(!s1.empty()) {
                p = s1.top();
                sum = p->val + carry;
                p->val = sum%10;
                carry = sum/10;
                s1.pop();
            }
            if(carry) {
                ListNode *head = new ListNode(1);
                head->next = p;
                return head;
            }
        }
        else {
            while(!s1.empty()) {
                p = s2.top();
                sum = p->val + s1.top()->val + carry;
                p->val = sum%10;
                carry = sum/10;
                s2.pop();
                s1.pop();
            }
            while(!s2.empty()) {
                p = s2.top();
                sum = p->val + carry;
                p->val = sum%10;
                carry = sum/10;
                s2.pop();
            }
            if(carry) {
                ListNode *head = new ListNode(1);
                head->next = p;
                return head;
            }
        }
        return p;
    }
};