#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        for (int i=num.size()-1;i>0;--i)
        {
            if (num[i] > num[i-1]) {
                int j=0;
                for (j=i;j<num.size();++j) {
                    if (num[j]<=num[i-1])
                        break;
                }
                std::swap(num[j-1], num[i-1]);
                std::sort(num.begin()+i, num.end());
                return;
            }
        }
        std::reverse(num.begin(), num.end());
    }
};

int main()
{
    Solution s;
    vector<int> n;
    n.push_back(1);
    n.push_back(3);
    n.push_back(2);
    n.push_back(1);
    s.nextPermutation(n);
    return 0;
}