#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string rtnval;
        for (int l=0; l < num2.length(); ++l)
        {
            string str = mul(num1, num2[num2.length() - l - 1] - '0');
            str.append(l, '0');
            rtnval = add(str, rtnval);
        }
        return rtnval;
    }

    string mul(string num, int multypler) {
        string rtnval;
        rtnval.reserve(num.length() + 1);

        int jinwei = 0;
        for (int i=num.length() - 1; i>=0; --i)
        {
            int v = (int)(num[i] - '0') * multypler + jinwei;
            jinwei = v / 10;
            rtnval += (char)(v % 10 + '0');
        }
        if (jinwei)
            rtnval += jinwei + '0';
        std::reverse(rtnval.begin(), rtnval.end());
        return rtnval;
    }

    string add(string num1, string num2) {
        string rtnval;
        rtnval.reserve(std::max(num1.length(), num2.length()) + 1);

        int l1 = num1.length() - 1;
        int l2 = num2.length() - 1;
        int jinwei = 0;
        while (l1 >= 0 && l2 >= 0) {
            int v = (int)(num1[l1--] - '0' + num2[l2--] - '0') + jinwei;
            jinwei = v / 10;
            rtnval += (char)(v % 10 + '0');
        }
        while (l1 >= 0) {
            int v = (int)(num1[l1--] - '0') + jinwei;
            jinwei = v / 10;
            rtnval += (char)(v % 10 + '0');
        }
        while (l2 >= 0) {
            int v = (int)(num2[l2--] - '0') + jinwei;
            jinwei = v / 10;
            rtnval += (char)(v % 10 + '0');
        }
        if (jinwei)
            rtnval += jinwei + '0';
        std::reverse(rtnval.begin(), rtnval.end());
        return rtnval;
    }
};

int main()
{
    Solution s;
    cout << s.multiply("0", "0");
    return 0;
}