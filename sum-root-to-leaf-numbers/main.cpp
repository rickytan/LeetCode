#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    void visit(TreeNode *root, int num, int &sum) {
        if (!root->left & !root->right) {
            sum += 10 * num + root->val;
        }
        if (root->left) {
            visit(root->left, 10 * num + root->val, sum);
        }
        if (root->right) {
            visit(root->right, 10 * num + root->val, sum);
        }
    }

    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;

        int sum = 0;
        visit(root, 0, sum);
        return sum;
    }
};

int main()
{
    Solution s;
    s.sumNumbers(new TreeNode(1, new TreeNode(2), new TreeNode(3)));
    return 0;
}