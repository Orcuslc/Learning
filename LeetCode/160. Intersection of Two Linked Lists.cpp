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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        // connect B.last with B.head;
        ListNode* p = headB;
        int count = 0;
        while(p->next) {
            p = p->next;
            count++;
        }
        p->next = headB;
             
        // if A and B intersects, then starting from A.head, we can get a circle in this linked list;
        ListNode* fast = headA, *slow = headA;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(!fast || !fast->next) { // no intersection;
        // disconnect B.last with B.head;
            p->next = NULL;
            return NULL;
        }
        
        // using the same algorithm from No.142 (Linked List Cycle II), we can get the entry of circle, which is the first node of intersection;
        ListNode* entry = headA;
        while(slow != entry) {
            entry = entry->next;
            slow = slow->next;
        }
        
        // disconnect B.last with B.head;
        p->next = NULL;
        return entry;
    }
};

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
        if(!head || !head->next) return;
        
        // find the middle of list
        ListNode* fast = head->next, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // reverse the last half;
        ListNode* head2 = slow->next;
        slow->next = NULL;
        fast = head2->next;
        head2->next = NULL;
        while(fast) {
            slow = fast->next;
            fast->next = head2;
            head2 = fast;
            fast = slow;
        }
        
        // merge
        for(slow = head, fast = head2; slow; ) {
            ListNode* tmp = slow->next;
            slow->next = fast;
            slow = slow->next;
            fast = tmp;
        }
    }
};