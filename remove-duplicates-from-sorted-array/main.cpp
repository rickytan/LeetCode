#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1)
            return n;

        int value = A[0];
        int pos = 1;
        int size = n;
        for (int i=1; i<n; ++i) {
            if (A[i] == value) {
                --size;
            }
            else {
                value = A[i];
                A[pos++] = A[i];
            }
        }
        return size;
    }
};

int main()
{
    int A[] = {1,1,2};
    Solution s;
    cout << s.removeDuplicates(A, sizeof(A) / sizeof(int));
    return 0;
}