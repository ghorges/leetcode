/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param l1 ListNode类 
     * @param l2 ListNode类 
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(l1 || l2) {
            if (l1 == NULL) {
                p->next = l2;
                return head->next;
            }
            if (l2 == NULL) {
                p->next = l1;
                return head->next;
            }
            if (l1->val > l2->val) {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            } else {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
        }
        return head->next;
    }
};








