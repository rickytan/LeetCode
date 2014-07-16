#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<pair<TreeNode *, int>> treeStack;
        treeStack.push(make_pair(root, 0));

        int count = 0;
        while (!treeStack.empty()) {
            pair<TreeNode *, int> p = treeStack.front();
            treeStack.pop();

            TreeNode *top = p.first;
            int level = p.second;

            if (level >= result.size())
                result.push_back(vector<int>());

            result[level].push_back(top->val);

            if (top->left) {
                treeStack.push(make_pair(top->left, level+1));
                //result[level].push_back(top->left->val);
            }
            if (top->right) {
                treeStack.push(make_pair(top->right, level+1));
                //result[level].push_back(top->right->val);
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{

    return 0;
}