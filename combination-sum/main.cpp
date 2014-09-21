#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;

        set<int> numbers;
        for (int i=0; i<candidates.size(); ++i)
        {
            if (candidates[i] < target)
                numbers.insert(candidates[i]);
            else if (candidates[i] == target) {
                vector<int> n(1);
                n[0] = target;
                result.push_back(n);
            }
        }
        if (numbers.empty())
            return result;

        for (set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        {
            int num = *it;
            vector<vector<int> > sub_result = combinationSum(candidates, target - num);
            for (vector<vector<int> >::iterator it = sub_result.begin(); it != sub_result.end(); ++it)
            {
                it->push_back(num);
                std::sort(it->begin(), it->end());
            }
            result.insert(result.end(), sub_result.begin(), sub_result.end());
            std::sort(result.begin(), result.end());
            result.erase(std::unique(result.begin(), result.end()), result.end());
        }
        
        return result;
    }
};

void dump(vector<vector<int> > value)
{
    for (int i=0;i < value.size(); ++i)
    {
        cout << "[";
        for (int j=0;j < value[i].size(); ++j)
        {
            cout << value[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main()
{
    Solution s;
    vector<int> candidate;
    candidate.push_back(2);
    candidate.push_back(3);
    candidate.push_back(6);
    candidate.push_back(7);
    dump(s.combinationSum(candidate, 12));
    return 0;
}