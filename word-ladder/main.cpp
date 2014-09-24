#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>


using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, set<string> &dict) {
        map<string, map<string, string> > M;
        vector<string> S, E;
        for (set<string>::iterator it = dict.begin(); it!=dict.end(); ++it)
        {
            if (diff(start, *it) == 1) {
                S.push_back(*it);
                M[*it][start] = start;
            }
            if (diff(end, *it) == 1) {
                E.push_back(*it);
                M[*it][end] = end;
            }
            for (set<string>::iterator inner = dict.begin(); inner!=dict.end(); ++inner)
            {
                if (diff(*it, *inner) == 1) {
                    M[*it][*inner] = *inner;
                }
            }
        }
        bool found = false;
        int path = INT_MAX;
        
    }

    int diff(string &a, string &b) {
        int score = 0;
        int len = a.length();
        for (int i=0;i<len;++i)
        {
            if (a[i] != b[i])
                score++;
        }
        return score;
    }
};

int main()
{

    return 0;
}