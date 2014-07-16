#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode *n) : val(x), next(n) {}
 };

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        return reverseList(head, k);
    }

    ListNode *reverseList(ListNode *head, int k) {
        if (!head)
            return NULL;
        if (length(head) < k)
            return head;
        ListNode *p, *q, *m = NULL;
        p = head;
        q = p->next;
        if (q)
            m = q->next;
        head->next = reverseList(nextKNode(head, k), k);
        while (--k) {
            q->next = p;
            p = q;
            q = m;
            if (m)
                m = m->next;
        }
        return p;
    }

    ListNode *nextKNode(ListNode *head, int k) {
        while (head && k--) {
            head = head->next;
        }
        return head;
    }

    int length(ListNode *head) {
        int count = 0;
        while (head) {
            head = head->next;
            ++count;
        }
        return count;
    }
};

int main()
{
    Solution s;
    ListNode *h = s.reverseKGroup(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 1);
    while (h) {
        cout << h->val << " ";
        h = h->next;
    }
}