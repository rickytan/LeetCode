#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> rtnval;
        if (n > 0) {
            rtnval.push_back(0);
            for (int i=0; i<n; ++i)
            {
                int size = rtnval.size();
                for (int j=size-1; j>=0; --j)
                {
                    rtnval.push_back(rtnval[j] | 1 << i);
                }
            }
        }
        return rtnval;
    }
};

int main()
{
    Solution s;
    s.grayCode(2);
    return 0;
}