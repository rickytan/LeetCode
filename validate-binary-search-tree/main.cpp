#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root)
            return true;
        if (root->left && maxValue(root->left) >= root->val)
            return false;
        if (root->right && minValue(root->right) <= root->val)
            return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }

    int minValue(TreeNode *root) {
        if (!root->left)
            return root->val;
        return minValue(root->left);
    }

    int maxValue(TreeNode *root) {
        if (!root->right)
            return root->val;
        return maxValue(root->right);
    }
};

int main()
{

    return 0;
}
