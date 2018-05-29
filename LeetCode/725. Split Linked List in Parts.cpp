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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        if(!root) {
            for(int i = 0; i < k; i++) {
                res.push_back(NULL);
            }
            return res;
        }
        ListNode* p = root; 
        int count = 1;
        while(p->next) {
            p = p->next;
            count++;
        }
        p = root;
        int n = count/k, m = count - n*k;
        if(n == 0) {
            for(int i = 0; i < m; i++) {
                res.push_back(p);
                ListNode* q = p;
                p = p->next;
                q->next = NULL;
            }
            for(int i = m; i < k; i++) 
                res.push_back(NULL);
        }
        else {
            for(int i = 0; i < m; i++) {
                res.push_back(p);
                for(int j = 0; j < n; j++)
                    p = p->next;
                ListNode* q = p;
                p = p->next;
                q->next = NULL;
            }
            for(int i = m; i < k; i++) {
                if(!p) res.push_back(NULL);
                else {
                    res.push_back(p);
                    for(int j = 0; j < n-1; j++)
                        p = p->next;
                    ListNode* q = p;
                    p = p->next;
                    q->next = NULL;
                }
            }
        }
        
        return res;
    }
};