#include <iostream>

using namespace std;


class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int write_pos = -1;
        int index_pos = 0;
        int count = 0;
        for (;index_pos < n; ++index_pos)
        {
            if (A[index_pos] == elem) {
                if (write_pos == -1)
                    write_pos = index_pos;
                ++count;
            }
            else if (write_pos >= 0) {
                A[write_pos++] = A[index_pos];
            }
        }
        return n - count;
    }
};

int main()
{
    int A[] = {1,3,2,5,2,4,0};
    Solution s;
    cout << s.removeElement(A, sizeof(A)/sizeof(int), 2);
    return 0;
}
