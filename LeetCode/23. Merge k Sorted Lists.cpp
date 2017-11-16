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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return NULL;
        while(lists.size() > 1) {
            lists.push_back(merge2Lists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
    
    ListNode* merge2Lists(ListNode* h1, ListNode* h2) {
        if(!h1) return h2;
        if(!h2) return h1;
        if(h1->val <= h2->val) {
            h1->next = merge2Lists(h1->next, h2);
            return h1;
        }
        else {
            h2->next = merge2Lists(h2->next, h1);
            return h2;
        }
    }
};