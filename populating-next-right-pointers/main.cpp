#include <iostream>

using namespace std;


struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    TreeLinkNode(int x, TreeLinkNode *l, TreeLinkNode *r) : val(x), left(l), right(r), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root || !root->left || !root->right)
            return;

        root->left->next = root->right;
        root->right->next = left(root->next);
        connect(root->right);
        connect(root->left);
    }

    TreeLinkNode *left(TreeLinkNode *root) {
        if (!root)
            return NULL;
        return root->left;
    }
};

int main()
{

    return 0;
}