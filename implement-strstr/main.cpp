#include <iostream>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!haystack || !needle)
        {
            return NULL;
        }

        if (!*haystack && !*needle)
            return haystack;
        string s(haystack);
        char *p = haystack;
        char *q = needle;
        char *result = NULL;
        while (*p) {
            q = needle;
            result = p;
            while (*p && *q && *p++ == *q) {
                ++q;
            }
            if (!*q)
                return result;
            else {
                p = result + 1;
                result = NULL;
            }
        }
        return NULL;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("mississippi", "issip") << endl;
    return 0;
}

