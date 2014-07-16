#include <iostream>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x <= 1)
            return x;
        double value = (double)x;
        double root = value / 2;
        while (true) {
            double tmp = root / 2 + value / 2 / root;
            if (root - tmp < 1.f) {
                root = tmp;
                break;
            }
            root = tmp;
        }
        int result = (int)root;
        if ((double)result * result > value)
            --result;
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.sqrt(2147395600);
    return 0;
}
