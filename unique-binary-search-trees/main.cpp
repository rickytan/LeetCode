#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    map<int, int> cache;

    int numTrees(int n) {
        if (cache.count(n))
            return cache[n];

        if (n == 0) {
            cache[n] = 1;
            return 1;
        }

        if (n == 1) {
            cache[n] = 1;
            return 1;
        }

        int sum = 0;
        for (int i=0;i < n; ++i)
        {
            sum += numTrees(n - 1 - i) * numTrees(i);
        }

        cache[n] = sum;
        return sum;
    }
};

int main()
{
    Solution s;
    cout<<s.numTrees(5)<<endl;
    return 0;
}