#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int cols = grid[0].size();
        if (cols == 0)
            return 0;

        vector<vector<int>> min_sum = grid;
        
        int sum = 0;
        for (int i=0; i<cols; ++i)
        {
            sum += grid[0][i];
            min_sum[0][i] = sum;
        }
        sum = 0;
        for (int i=0; i<rows; ++i)
        {
            sum += grid[i][0];
            min_sum[i][0] = sum;
        }

        for (int i=1; i<rows; ++i)
        {
            for (int j=1; j<cols; ++j)
            {
                min_sum[i][j] = min(min_sum[i][j - 1], min_sum[i - 1][j]) + grid[i][j];
            }
        }
        return min_sum[rows - 1][cols - 1];
    }
};

int main()
{
    vector<vector<int>> grid(2);
    grid[0].push_back(1);
    grid[0].push_back(2);
    grid[0].push_back(5);
    grid[1].push_back(3);
    grid[1].push_back(2);
    grid[1].push_back(1);
    Solution s;
    s.minPathSum(grid);
    return 0;
}