#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int closest = INT_MAX;
        int value = 0;

        std::sort(num.begin(), num.end());
        int length = num.size();
        for (int a=0; a<length - 2;)
        {
            int b = a + 1;
            int c = length - 1;
            while (b < c) {
                int sum = num[a] + num[b] + num[c];
                if (abs(sum - target) < closest) {
                    closest = abs(sum - target);
                    value = sum;
                }

                if (sum == target) {
                    ++b;
                    while (b < length && num[b] == num[b-1])
                        ++b;
                    --c;
                    while (c > b && num[c] == num[c+1])
                        --c;
                }
                else if (sum < target) {
                    b++;
                }
                else {
                    c--;
                }
            }
            ++a;
            while (a < length - 2 && num[a] == num[a-1])
                ++a;
        }
        return value;
    }
};

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(-4);
    num.push_back(-1);
    //num.push_back(16);
    //num.push_back(32);
    //num.push_back(64);
    //num.push_back(128);

    Solution s;
    cout << s.threeSumClosest(num, 1);
    return 0;
}
