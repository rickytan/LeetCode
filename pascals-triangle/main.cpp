#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result(numRows);
        if (numRows > 0) {
            result[0].push_back(1);
            for (int row = 1;row < numRows; ++row) {
                result[row].push_back(1);
                for (int i=1;i < row; ++i)
                {
                    result[row].push_back(result[row-1][i-1] + result[row-1][i]);
                }
                result[row].push_back(1);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    s.generate(5);
    return 0;
}