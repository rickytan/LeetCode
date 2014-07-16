#include <iostream>
#include <algorithm>

class Solution {
public:
    bool canJump(int A[], int n) {
        int maxPos = 0;
        for (int i=0;i<n;++i)
        {
            maxPos = std::max(maxPos, A[i] + i);
            if (A[i] == 0) {
                if (maxPos <= i && i != n-1)
                    return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}