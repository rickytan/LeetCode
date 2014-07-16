#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.empty())
            return NULL;

        int value = preorder[0];
        preorder.erase(preorder.begin());
        TreeNode *root = new TreeNode(value);
        vector<int>::iterator index = std::find(inorder.begin(), inorder.end(), value);
        vector<int> left(inorder.begin(), index);
        root->left = buildTree(preorder, left);
        vector<int> right(index + 1, inorder.end());
        root->right = buildTree(preorder, right);
        return root;
    }
};

int main()
{

}
