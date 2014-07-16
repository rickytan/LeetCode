#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        for (int i=0; i<height.size(); ++i)
        {
            int value = height[i];
            int start = 0;
            int end = height.size() - 1;
            for (int j=0; j < i; ++j) {
                if (height[j] < value)
                    start = j + 1;
            }

            for (int j=i+1; j < height.size(); ++j) {
                if (height[j] < value)
                    end = j - 1;
            }
            
            int area = value * (end - start);
            if (area > maxArea)
                maxArea = area;
        }
        return maxArea;
    }
};

int main()
{
    Solution s;
    vector<int> h;
    h.push_back(2);
    h.push_back(1);
    h.push_back(5);
    h.push_back(6);
    h.push_back(2);
    h.push_back(3);
    cout << s.largestRectangleArea(h) << endl;
    return 0;
}