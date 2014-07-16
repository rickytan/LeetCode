#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int length = L[0].length();
        int start = 0;
        vector<int> result;
        while (start <= S.length() - length) {
            int min = S.length();
            for (vector<string>::iterator it = L.begin(); it != L.end(); ++it) {
                int pos = S.find(*it, start);
                min = std::min(min, pos);
            }
            if (min == string::npos)
                break;
            vector<string> cL(L);
            int pos = min;
            while (!cL.empty()) {
                vector<string>::iterator found = std::find(cL.begin(), cL.end(), S.substr(pos, length));
                if (found != cL.end()) {
                    cL.erase(found);
                    pos += length;
                }
                else
                    break;
            }
            if (cL.empty()) {
                result.push_back(min);
            }
            start = min + length;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> L;
    L.push_back("foo");
    L.push_back("bar");
    s.findSubstring("barfoothefoobarman", L);
    return 0;
}