#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows = matrix.size();
        if (rows == 0)
            return false;
        int cols = matrix[0].size();
        if (cols == 0)
            return false;

        int start = 0;
        int end = rows - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (matrix[mid][0] > target) {
                end = mid - 1;
            }
            else if (matrix[mid][0] < target) {
                start = mid + 1;
            }
            else {
                return true;
            }
        }
        
        if (target < matrix[start][0]) {
            if (start > 0)
                --start;
            else
                return false;
        }
        if (target > matrix[start][cols - 1] && start == rows - 1) 
            return false;

        if (std::binary_search(matrix[start].begin(), matrix[start].end(), target))
            return true;
        return false;
    }
};

int main()
{
    int A[][4] = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,50}
    };
    int r = sizeof(A) / sizeof(A[0]);
    int c = sizeof(A[0]) / sizeof(A[0][0]);

    vector<vector<int>> matrix(r);
    for (int i=0;i<r;++i)
    {
        for (int j=0;j<c;++j)
        {
            matrix[i].push_back(A[i][j]);
        }
    }
    Solution s;
    cout << s.searchMatrix(matrix, 70);
    return 0;
}
