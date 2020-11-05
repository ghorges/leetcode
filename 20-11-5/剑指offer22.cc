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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p = head;
        int n = 0;
        while(p) {
            n++;
            p = p->next;
        }
        p = head;
        n -= k;
        int i = 0;
        while(p) {
            if (i == n) {
                return p;
            }
            i++;
            p = p->next;
        }
        return NULL;
    }
};
