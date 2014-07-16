#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if (length == 0)
            return 0;
        int result = 1;
        int max = 0;
        int start = 0;
        for (int i=1;i<length;++i)
        {
            string sub = s.substr(start, i - start);
            char ch = s[i];
            int pos = sub.find_last_of(ch);
            if (pos == string::npos) {
                ++result;
            }
            else {
                for (int j=i - pos; j >= max;--j)
                {
                    string sub = s.substr(i - j, j);
                    if (s.find(sub) == string::npos)
                        ++result;
                }
                start = pos + 1;
                max = std::max(max, result);
                result = 1;
            }
        }
        return std::max(result, max);
    }
};

int main()
{
    Solution s;
    string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}