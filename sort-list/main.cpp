#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return head;
        
        int count = countNode(head);
        ListNode *first = NULL, *second = NULL;
        splitList(head, count, first, second);
        head = mergeList(first, second);
        return head;
    }

    void splitList(ListNode *head, int count, ListNode *&first, ListNode *&second) {
        first = head;
        second = NULL;
        if (count <= 1)
            return;

        ListNode *p = head;
        for (int i=0; i < count / 2; ++i) {
            p = head;
            head = head->next;
        }
        p->next = NULL;
        second = head;

        ListNode *f = NULL, *s = NULL;
        splitList(first, countNode(first), f, s);
        first = mergeList(f, s);
        splitList(second, countNode(second), f, s);
        second = mergeList(f, s);
    }

    ListNode *mergeList(ListNode *first, ListNode *second) {
        if (!first) return second;
        if (!second) return first;

        ListNode dummy(0);
        ListNode *head = &dummy;
        ListNode *q, *p;
        while (first && second) {
            p = first;
            q = second;
            if (first->val < second->val) {
                head->next = first;
                head = first;
                first = first->next;
            }
            else {
                head->next = second;
                head = second;
                second = second->next;
            }
        }
        if (!second)
            head->next = p;
        if (!first)
            head->next = q;
        return dummy.next;
    }

    int countNode(ListNode *head) {
        int count = 0;
        while (head) {
            ++count;
            head = head->next;
        }
        return count;
    }
};

int main()
{
    Solution s;
    ListNode *h = s.sortList(new ListNode(5, new ListNode(9, new ListNode(2, new ListNode(3, new ListNode(7, new ListNode(1)))))));
    while (h) {
        cout<< h->val << ' ';
        h = h->next;
    }
    return 0;
}