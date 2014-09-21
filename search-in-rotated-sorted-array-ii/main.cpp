#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int offset = 0;
        while (A[offset] <= A[(offset + 1) % n])
            ++offset;
        offset = (++offset) % n;
        vector<int> sorted(n);
        std::rotate_copy(A, A+offset, A+n, sorted.begin());
        int start = 0;
        int end = n - 1;
        int mid = (start + end) / 2;
        while (start < end) {
            mid = (start + end) / 2;
            if (sorted[mid] > target)
                end = mid - 1;
            else if (sorted[mid] < target)
                start = mid + 1;
            else
                break;
        }
        mid = (start + end) / 2;
        if (sorted[mid] == target)
            return true;
        return false;
    }
};

int main()
{
    int A[] = {1, 1, 3, 1, 1};
    Solution s;
    cout << s.search(A, 5, 3);
    return 0;
}
