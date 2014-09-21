#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2)
            return n;

        int value0 = A[0];
        int value1 = A[1];
        int pos = 2;
        int size = n;
        for (int i=2; i<n;++i) {
            int t = A[i];
            if (value1 == value0 && value0 == t) {
                --size;
            }
            else {
                value0 = value1;
                value1 = t;
                A[pos++] = t;
            }
        }
        return size;
    }
};

int main()
{
    Solution s;
    int a[] = {1, 1, 1, 2, 2, 3};
    s.removeDuplicates(a, 6);
    return 0;
}