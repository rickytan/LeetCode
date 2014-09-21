#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        stack<int> s;
        height.push_back(0);
        for (int i=0;i<height.size();++i)
        {
            if (s.empty() || height[i] > height[s.top()]) {
                s.push(i);
            }
            else {
                int tmp = s.top();
                s.pop();
                int area = height[tmp] * (s.empty() ? i : (i - s.top() - 1));
                maxArea = std::max(maxArea, area);
                i--;
            }
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