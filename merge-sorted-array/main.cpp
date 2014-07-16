#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int a = 0, b = 0;
        for (int i=m-1; i>=0; --i) {
            A[i+n] = A[i];
        }
        int index = 0;
        while (a < m && b < n) {
            if (A[a+n] < B[b]) {
                A[index++] = A[(a++)+n];
            }
            else {
                A[index++] = B[b++];
            }
        }
        while (a < m)
            A[index++] = A[(a++)+n];
        while (b < n)
            A[index++] = B[b++];
    }
};

int main()
{
    Solution s;
    int A[] = {1, 3, 4, 5, 9, 11, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int B[] = {1, 2, 5, 6, 8, 9, 10};
    s.merge(A, 7, B, 7);
    return 0;
}