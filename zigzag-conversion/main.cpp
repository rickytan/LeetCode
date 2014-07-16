#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 0 || nRows == 1)
            return s;
        string result(s);
        int step = 2 * nRows - 2;
        int length = s.length();
        int l = 0;
        for (int r = 0; r < nRows; ++r)
        {
            if (r == 0 || r == nRows - 1) {
                for (int i = 0; i * step + r < length; ++i)
                {
                    result[l++] = s[i * step + r];
                }
            }
            else {
                for (int i=0;; ++i)
                {
                    if (i * step + r < length)
                        result[l++] = s[i * step + r];
                    else
                        break;
                    if (i * step + step - r < length)
                        result[l++] = s[i * step + step - r];
                    else
                        break;
                }
            }
        }
        
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.convert("a", 1);
    return 0;
}
