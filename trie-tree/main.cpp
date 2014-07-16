#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class TreeNode {
public:
    TreeNode(): m_value(0), m_fullword(false) {};
    int &value() {
        return m_value;
    }

    bool &isWord() {
        return m_fullword;
    }

    TreeNode *subtree(char path) {
        return m_children[path];
    }

    TreeNode *addChild(char path) {
        TreeNode *node = new TreeNode;
        m_children[path] = node;
        return node;
    }

    int m_value;
    bool m_fullword;
    map<char, TreeNode*> m_children;
};

class TrieTree {
public:
    TrieTree() {
        root = new TreeNode;
    }

    void addWord(string word) {
        TreeNode *node = root;
        node->value()++;
        for (string::iterator it=word.begin(); it != word.end(); ++it)
        {
            TreeNode *snode = node->subtree(*it);
            if (!snode) {
                snode = node->addChild(*it);
            }
            snode->value()++;
            node = snode;
        }
        node->isWord() = true;
    }

    void addWords(vector<string> words) {

    }

    int wordsStartWith(string prefix) {
        TreeNode *node = findNodeWithPath(prefix);
        if (node)
            return node->value();
        return 0;
    }

    TreeNode *findNodeWithPath(string path) {
        TreeNode *node = root;
        int index = 0;
        while (node && index < path.length()) {
            node = node->subtree(path[index++]);
        }
        return node;
    }

private:
    TreeNode *root;
};

int main()
{
    int N;
    string input_word;
    string query_word;
    TrieTree trie_tree;

    cin >> N;
    while (N--) {
        cin >> input_word;
        trie_tree.addWord(input_word);
    }

    cin >> N;
    while (N--) {
        cin >> query_word;
        cout << trie_tree.wordsStartWith(query_word) << endl;
    }
    return 0;
}