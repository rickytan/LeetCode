#include <iostream>
#include <vector>
#include <map>

using namespace std;



class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1)
            return 1;
        int a = m - 1;
        int b = n - 1;
        if (a > b)
            std::swap(a, b);

        int c = a + b;
        unsigned long long s = 1;
        for (int i=b+1;i<=c;++i)
            s *= i;
        for (int i=2;i<=a;++i)
            s /= i;
        return (int)s;
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(4,4);
    return 0;
}