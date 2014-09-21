#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        vector<int> leftCapacity(n);
        vector<int> rightCapacity(n);

        int h = 0;
        for (int i=0;i<n;++i)
        {
            if (A[i] > h) {
                h = A[i];
            }
            else {
                leftCapacity[i] = h - A[i];
            }
        }
        h = 0;
        int water = 0;
        for (int i=n-1;i>=0;--i)
        {
            if (A[i] > h) {
                h = A[i];
            }
            else {
                rightCapacity[i] = h - A[i];
                water += std::min(rightCapacity[i], leftCapacity[i]);
            }
        }
        return water;
    }
};

int main()
{
    Solution s;
    int h[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    s.trap(h, 12);
    return 0;
}