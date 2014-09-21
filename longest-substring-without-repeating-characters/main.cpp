#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if (length == 0)
            return 0;

        int maxLength = 0;
        map<char, int> m;
        int start = 0;
        for (int i=0;i<length;++i)
        {
            char ch = s[i];
            if (m.count(ch)) {
                maxLength = std::max(maxLength, i - start);
                start = std::max(start, m[ch] + 1);
            }
            m[ch] = i;
        }
        maxLength = std::max(maxLength, length - start);
        return maxLength;
    }
};

int main()
{
    Solution s;
    string str = "qopubjguxhxdipfzwswybgfylqvjzhar";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}