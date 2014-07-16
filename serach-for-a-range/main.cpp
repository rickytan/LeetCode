#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start = 0;
        int end = n;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (A[mid] > target) {
                end = mid - 1;
            }
            else if (A[mid] < target) {
                start = mid + 1;
            }
            else {
                break;
            }
        }
        if (start > end) {
            vector<int> r(2);
            r[0] = -1;
            r[1] = -1;
            return r;
        }

        start = mid;
        while (--start >= 0 && A[start] == target)
            ;
        ++start;

        end = mid;
        while (++end < n && A[end] == target)
            ;
        --end;

        vector<int> r;
        r.push_back(start);
        r.push_back(end);
        return r;
    }
};

int main()
{
    int A[] = {0,0,2,3,4,4,4,5};
    Solution s;
    vector<int> r = s.searchRange(A, sizeof(A) / sizeof(int), 5);
    r[0] = 1;
    return 0;
}
