#include <iostream>
#include <algorithm>

class Solution {
public:
    int getMedian(int Arr[], int start, int end) {
        return Arr[(start + end)/2];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int *arr = new int[m + n];
        memcpy(arr + 0, A, sizeof(int) * m);
        memcpy(arr + m, B, sizeof(int) * n);
        std::sort(arr, arr + m + n);
        
        if (!((m + n) % 2)) {
            return .5 * (arr[(m+n)/2] + arr[(m+n-1)/2]);
        }
        else
            return arr[(m+n)/2];
    }
};

int main(int argc, char *argv)
{
    int A[] = {1, 2};
    int B[] = {2, 3};
    Solution s;
    std::cout << s.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)) << std::endl;
    return 0;
}