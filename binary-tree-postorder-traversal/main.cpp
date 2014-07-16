#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {};
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

    void traversal(TreeNode *root, vector<int> &out) {
        if (!root)
            return;
        traversal(root->left, out);
        traversal(root->right, out);
        out.push_back(root->val);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), NULL));
    Solution s;
    vector<int> r= s.postorderTraversal(root);
    r[0] = 0;
    return 0;
}