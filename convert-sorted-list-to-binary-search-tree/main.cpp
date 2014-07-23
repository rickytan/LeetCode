#include <iostream>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int length = count(head);
        return buildSubtree(head, length);
    }

    TreeNode *buildSubtree(ListNode *head, int length) {
        if (!head)
            return NULL;
        if (length <= 1)
            return new TreeNode(head->val);
        
        ListNode *p = head, *q = NULL;
        int i=0;
        while (i < length / 2) {
            ++i;
            q = p;
            p = p->next;
        }
        TreeNode *root = new TreeNode(p->val);
        root->left = buildSubtree(head, (length - 1) / 2);
        root->right = buildSubtree(p->next, (length - 1) / 2);
        return root;
    }

    int count(ListNode *head) {
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
    s.sortedListToBST(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))));
    return 0;
}
