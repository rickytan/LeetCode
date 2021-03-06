#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;

        int profit = 0;
        int min = prices[0];
        for (int i=1; i<prices.size(); ++i)
        {
            min = std::min(min, prices[i]);
            profit = std::max(profit, prices[i] - min);
        }
        return profit;
    }
};

int main()
{
    vector<int> p;
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);
    p.push_back(4);
    p.push_back(5);
    p.push_back(6);
    p.push_back(1);
    p.push_back(4);
    Solution s;
    cout << s.maxProfit(p);
    return 0;
}