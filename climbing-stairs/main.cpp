#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    map<int, int> cache;

    Solution () {
        cache[0] = 1;
        cache[1] = 1;
        cache[2] = 2;
    }

    int climbStairs(int n) {
        if (cache.count(n))
            return cache[n];
        cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return cache[n];
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(40);
}