#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *n) : val(x), next(n) {};
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *p = head;
        head = head->next;
        p->next = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = NULL;
            p = insertNode(p, head);
            head = next;
        }
        return p;
    }

    ListNode *insertNode(ListNode *head, ListNode *node) {
        ListNode *p = head;
        ListNode *q = NULL;
        while (p && node->val > p->val) {
            q = p;
            p = p->next;
        }
        if (q) {
            node->next = p;
            q->next = node;
        }
        else {
            node->next = p;
            head = node;
        }
        return head;
    }
};

int main()
{
    Solution s;
    s.insertionSortList(new ListNode(1, new ListNode(3, new ListNode(2, new ListNode(0)))));
    return 0;
}