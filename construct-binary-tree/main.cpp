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

    TreeNode *splitArray(vector<int> &arr, int begin, int end, vector<int> &preorder, int & level) {
        if (begin > end) {
            --level;
            return NULL;
        }

        int root = std::find(arr.begin(), arr.end(), preorder[level]) - arr.begin();
        TreeNode *node = new TreeNode(arr[root]);
        if (begin == end) {
            return node;
        }

        node->left = splitArray(arr, begin, root - 1, preorder, ++level);
        node->right = splitArray(arr, root + 1, end, preorder, ++level);
        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0)
            return NULL;
        int level = 0;
        return splitArray(inorder, 0, inorder.size() - 1, preorder, level);
    }
};

int main(int argc, char *argv)
{
    vector<int> p, i;
    p.push_back(1);
    p.push_back(3);
    p.push_back(2);
    p.push_back(4);
    i.push_back(1);
    i.push_back(2);
    i.push_back(3);
    i.push_back(4);
    Solution s;
    cout<<s.buildTree(p,i);
    return 0;
}