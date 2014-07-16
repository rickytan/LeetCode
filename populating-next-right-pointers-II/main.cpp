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
        if (!root)
            return;
    
        if (root->left && root->right)
            root->left->next = root->right;
        else if (root->left)
            root->left->next = left(root->next);

        if (root->right)
            root->right->next = left(root->next);
        connect(root->right);
        connect(root->left);
    }

    TreeLinkNode *left(TreeLinkNode *root) {
        if (!root)
            return NULL;
        if (root->left)
            return root->left;
        if (root->right)
            return root->right;
        return left(root->next);
    }
};

int main()
{

    return 0;
}