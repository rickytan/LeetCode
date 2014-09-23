#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string insertSpaces(const string &s) {
        int length = s.length();
        string new_str;
        new_str.reserve(length * 2 + 2);
        new_str.append("^");
        string part = " 0";
        for (int i=0; i < length; ++i)
        {
            part[1] = s[i];
            new_str.append(part);
        }
        new_str.append(" ");
        return new_str;
    }

    string longestPalindrome(string s) {
        string str = insertSpaces(s);
        vector<int> p(str.length());
        int mx = 0, id = 0;
        for (int i = 1; str[i] != '\0'; i++) {
            p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
            while (str[i + p[i]] == str[i - p[i]])
                p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        vector<int>::iterator it = std::max_element(p.begin(), p.end());
        int pos = it - p.begin();
        int length = *it - 1;
        return s.substr((pos - 1) / 2 - length / 2, length);
    }
};

int main()
{
    Solution s;
    s.longestPalindrome("aaabaaaa");
    return 0;
}