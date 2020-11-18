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
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        int n1 = 0, n2 = 0;
        ListNode*p1 = headA, *p2 = headB;
        while(p1) {
            n1++;
            p1 = p1->next;
        }
        while(p2) {
            n2++;
            p2 = p2->next;
        }
        if (n1 < n2) {
            ListNode *swap = headA;
            headA = headB;
            headB = swap;

            int n = n1;
            n1 = n2;
            n2 = n;
        }
        while (n1 > n2) {
            headA = headA->next;
            n1--;
        }
        while(headA) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
