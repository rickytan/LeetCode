#include <iostream>
#include <vector>

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

    void traversal(TreeNode *root, vector<int> &out) {
        if (!root)
            return;
        out.push_back(root->val);
        traversal(root->left, out);
        traversal(root->right, out);
    }
};

int main()
{

    return 0;
}