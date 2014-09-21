#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int maxIdx = -1;
        int minIdx = -1;
        int maxGas = INT_MIN;
        int minGas = INT_MAX;
        int total = 0;
        for (int idx = 0; idx < gas.size(); ++idx)
        {
            int left = gas[idx] - cost[idx];
            if (left > maxGas) {
                maxGas = left;
                maxIdx = idx;
            }
            if (left < minGas) {
                minGas = left;
                minIdx = idx;
            }
            total += left;
        }
        if (total < 0)
            return -1;
        for (int i = 0; i < gas.size();++i)
        {
            int idx = (gas.size() + maxIdx - i) % gas.size();
            if (gas[idx] - cost[idx] >= 0)
                continue;
            else
                return (idx + gas.size() + 1) % gas.size();
        }
        return maxIdx;
    }
};

int main()
{
    Solution s;
    vector<int> gas;
    gas.push_back(1);
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(4);
    gas.push_back(5);

    vector<int> cost;
    cost.push_back(3);
    cost.push_back(4);
    cost.push_back(5);
    cost.push_back(1);
    cost.push_back(2);

    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}