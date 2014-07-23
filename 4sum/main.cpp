#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;

        std::sort(num.begin(), num.end());
        int length = num.size();
        for (int a=0; a<length - 3;)
        {
            for (int b=a+1; b<length - 2;)
            {

                int c = b + 1;
                int d = length - 1;
                while (c < d) {
                    int sum = num[a] + num[b] + num[c] + num[d];
                    if (sum == target) {
                        vector<int> item(4);
                        item[0] = num[a];
                        item[1] = num[b];
                        item[2] = num[c];
                        item[3] = num[d];
                        
                        result.push_back(item);
                        ++c;
                        while (c < length && num[c] == num[c-1])
                            ++c;
                        --d;
                        while (d > c && num[d] == num[d+1])
                            --d;
                    }
                    else if (sum < target) {
                        c++;
                    }
                    else {
                        d--;
                    }
                }
                ++b;
                while (b < length - 2 && num[b] == num[b-1])
                    ++b;
            }
            ++a;
            while (a < length - 3 && num[a] == num[a-1])
                ++a;
        }
        return result;
    }
};

int main()
{
    vector<int> S;
    S.push_back(1);
    S.push_back(0);
    S.push_back(-1);
    S.push_back(0);
    S.push_back(-2);
    S.push_back(2);

    Solution s;
    s.fourSum(S, 0);
    return 0;
}
