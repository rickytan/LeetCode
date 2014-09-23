#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, set<string> &dict) {
        if (dict.size() == 0)
            return vector<string>();
        unsigned int size = s.length();
        
        vector<pair<bool, vector<int> > > canBreak(size + 1, std::make_pair(false, vector<int>()));
        canBreak[size] = std::make_pair(true, vector<int>());
        for (int i=size - 1; i>=0 ; --i)
        {
            for (int j=i; j < size ; ++j)
            {
                if (dict.find(s.substr(i, j-i+1)) != dict.end() && canBreak[j+1].first) {
                    canBreak[i].first = true;
                    canBreak[i].second.push_back(j-i+1);
                }
            }
        }
        vector<string> rtnval;
        if (canBreak[0].first)
            buildString(s, canBreak, 0, rtnval, queue<string>());
        return rtnval;
    }

    void buildString(const string &s, vector<pair<bool, vector<int> > > &canBreak, int pos, vector<string> &value, queue<string> visit)
    {
        if (canBreak[pos].second.size() == 0) {
            string ss;
            while (!visit.empty()) {
                ss += visit.front() + " ";
                visit.pop();
            }
            value.push_back(ss.substr(0, ss.length() - 1));
            return;
        }

        for (int i=0; i<canBreak[pos].second.size(); ++i)
        {
            queue<string> q = visit;
            q.push(s.substr(pos, canBreak[pos].second[i]));
            buildString(s, canBreak, pos + canBreak[pos].second[i], value, q);
        }
    }
};

int main()
{
    set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    Solution s;
    s.wordBreak("catsanddog", dict);
    return 0;
}