#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int out = 0;
        long long dend = dividend, dor = divisor;
        int sign = 1;
        if (dividend < 0) {
            sign = -sign;
            dend = -dend;
        }
        if (divisor < 0) {
            sign = -sign;
            dor = -dor;
        }
        if (divisor == 1)
            return dividend;

        if (dend < dor)
            return 0;

        while (dend >= dor) {
            int times = 0;
            while (dend >= (dor << times))
                ++times;
            out += 1 << times - 1;
            dend -= dor << times - 1;
        }
        return out * sign;
    }
};

int main()
{
    Solution s;
    cout << s.divide(-2147483648, -2147483648);
    return 0;
}
