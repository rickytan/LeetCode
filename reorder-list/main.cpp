#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *n = NULL) : val(x), next(n) {}
};

class Solution {
public:

    void reorderList(ListNode *head) {
        if (!head)
            return;
        vector<ListNode *> pointorArr;
        ListNode *p = head;
        while (p) {
            pointorArr.push_back(p);
            p = p->next;
        }
        if (pointorArr.size() <= 2)
            return;

        for (int i=0;i<=pointorArr.size()/2;++i)
        {
            if (i) {
                pointorArr[pointorArr.size() - i]->next = pointorArr[i];
            }
            pointorArr[i]->next = pointorArr[pointorArr.size() - 1 - i];
        }
        pointorArr[pointorArr.size()/2]->next = NULL;
    }
};

int main()
{
    Solution s;
    s.reorderList(new ListNode(1, new ListNode(2, new ListNode(3))));
    return 0;
}