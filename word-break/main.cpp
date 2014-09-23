#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, set<string> &dict) {
        if (dict.size() == 0)
            return false;
        unsigned int size = s.length();
        vector<bool> canBreak(size + 1, false);
        canBreak[size] = true;
        for (int i=size - 1; i>=0 ; --i)
        {
            for (int j=i; j < size ; ++j)
            {
                if (dict.find(s.substr(i, j-i+1)) != dict.end() && canBreak[j+1]) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[0];
    }

};

int main()
{
    set<string> dict;
    //dict.insert("a");
    dict.insert("b");
    Solution s;
    cout << s.wordBreak("a", dict);
    return 0;
}