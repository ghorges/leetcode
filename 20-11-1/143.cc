// 还是用两个指针指向方便，用一个前置指针太容易出错了
// 用 vector 而不是 map，map 相对性能损耗高
// 也可以使用对后面的进行反转，然后合并
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // 建立一个 map 即可
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL) {
            return;
        }
        map<int, ListNode*> nodeData;
        int num = 0;
        ListNode *p = head;
        while (p) {
            nodeData[num++] = p;
            p = p->next;
        }
        int l = 1;
        //int l = 0;
        int r = num - 1;
        p = head;
        int temp = 1;
        while (l < r) {
            if (temp % 2) {
                p->next = nodeData[r--];
            } else {
                p->next = nodeData[l++];
            }

            p = p->next;
            temp++;
            /*
            nodeData[l]->next = nodeData[r];
            l++;
            if (l == r) {
                break;
            }
            nodeData[r]->next = nodeData[l];
            r--;
            */
        }
        if (num > 1) {
        if (num % 2 == 1) {
            p->next = nodeData[r];
        }
        nodeData[l]->next = NULL;
        }
        return;
    }
};
