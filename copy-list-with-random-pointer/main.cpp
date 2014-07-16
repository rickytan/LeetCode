
#include <iostream>
#include <map>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;

        std::map<RandomListNode *, RandomListNode *> p_pair;

        RandomListNode *list_copy = new RandomListNode(head->label);
        p_pair[head] = list_copy;

        if (p_pair.count(head->random))
            list_copy->random = p_pair[head->random];
        else if (head->random) {
            list_copy->random = new RandomListNode(head->random->label);
            p_pair[head->random] = list_copy->random;
        }

        RandomListNode *q = list_copy;
        RandomListNode *p = head->next;
        while (p) {
            if (p_pair.count(p)) {
                q->next = p_pair[p];
            }
            else {
                q->next = new RandomListNode(p->label);
                p_pair[p] = q->next;
            }

            if (p->random && p_pair.count(p->random)) {
                q->next->random = p_pair[p->random];
            }
            else if (p->random) {
                q->next->random = new RandomListNode(p->random->label);
                p_pair[p->random] = q->next->random;
            }
            p = p->next;
            q = q->next;
        }
        return list_copy;
    }
};

int main(int argc, char *argv)
{
    return 0;
}