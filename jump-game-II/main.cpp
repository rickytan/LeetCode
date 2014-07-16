#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int jump(int A[], int n) {
        int b0 = 0;

        int i=0;
        for (;b0 < n-1;++i)
        {
            int maxPos = 0;
            for (int j=0; j<=b0 ;++j)
            {
                if (A[j] + j > maxPos)
                    maxPos = A[j] + j;
            }
            b0 = maxPos;
        }

        return i;
    }
};

int main()
{
    Solution s;
    int A[] = {1,2};
    cout << s.jump(A, sizeof(A) / sizeof(int));
    return 0;
}