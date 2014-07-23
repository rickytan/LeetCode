#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;

        std::sort(num.begin(), num.end());
        int length = num.size();
        for (int a=0; a<length - 2;)
        {
            int b = a + 1;
            int c = length - 1;
            while (b < c) {
                int sum = num[a] + num[b] + num[c];
                if (sum == 0) {
                    vector<int> item(3);
                    item[0] = num[a];
                    item[1] = num[b];
                    item[2] = num[c];
                    //if (!std::binary_search(result.begin(), result.end(), item))
                        result.push_back(item);
                    ++b;
                    while (b < length && num[b] == num[b-1])
                        ++b;
                    --c;
                    while (c > b && num[c] == num[c+1])
                        --c;
                }
                else if (sum < 0) {
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
        return result;
    }
};

int main()
{
    vector<int> S;


    Solution s;
    s.threeSum(S);
    return 0;
}
