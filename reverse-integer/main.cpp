#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        queue<char> nums;
        while (x) {
            nums.push(x % 10);
            x /= 10;
        }
        long long v = 0;
        while (!nums.empty()) {
            v = 10*v + nums.front();
            nums.pop();
        }
        return v;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(23124310) << endl;
    return 0;
}