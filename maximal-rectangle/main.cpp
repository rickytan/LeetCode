#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int height = matrix.size();
        if (height == 0) return 0;
        int width = matrix[0].size();
        int cs = -1, ce = -1;
        int rs = -1, re = -1;
        for (int row=0; row < height; ++row) {
            for (int col=0; col < width; ++col) {
                int value = matrix[row][col];

            }
        }
        
    }
};

int main()
{

    return 0;
}