#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int num = 0;
        std::sort(ratings.begin(), ratings.end());
        vector<int>::iterator start = ratings.begin();
        vector<int>::iterator it = ratings.begin() + 1;
        
        vector<int> values;
        for (;it != ratings.end(); ++it)
        {
            if (*start != *it) {
                values.push_back(it - start);
                start = it;
            }
        }
        values.push_back(it - start);
        for (int i=0; i<values.size(); ++i)
        {
            num += values[i] * (i + 1);
        }
        return num;
    }
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    Solution s;
    s.candy(v);
    return 0;
}