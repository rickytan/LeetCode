#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        sort(num.begin(), num.end());
        int max = 1;
        int n = 1;
        int value = num[0];
        for (unsigned int i=1;i<num.size();++i)
        {
            if (num[i] == ++value) {
                ++n;
            }
            else if (num[i] == --value) {

            }
            else {
                value = num[i];
                max = std::max(max, n);
                n = 1;
            }
        }
        
        return std::max(max, n);
    }
};

int main(int argc, char *argv)
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(0);
    A.push_back(1);

    Solution s;
    std::cout << s.longestConsecutive(A) << std::endl;
    return 0;
}