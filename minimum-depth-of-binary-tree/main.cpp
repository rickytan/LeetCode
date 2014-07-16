#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        int depth = 0;
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;

        int l = INT_MAX, r = INT_MAX;
        if (root->left)
            l = minDepth(root->left);
        if (root->right)
            r = minDepth(root->right);
        depth = std::min(l, r) + 1;
        return depth;
    }
};

int main()
{
    Solution s;
    cout << s.minDepth(new TreeNode(0, NULL, NULL));
    return 0;
}