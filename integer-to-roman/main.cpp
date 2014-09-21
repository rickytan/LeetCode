#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        struct {
            int value;
            string roman;
        } table[] = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        string romanString = "";
        for (int i=12; i>=0 && num > 0; --i)
        {
            while (num >= table[i].value) {
                num -= table[i].value;
                romanString += table[i].roman;
            }
        }
        return romanString;
    }
};

int main()
{
    Solution s;
    s.intToRoman(233);
    return 0;
}