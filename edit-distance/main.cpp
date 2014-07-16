#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dist;
        dist.resize(word1.length() + 1);
        for (int i=0; i<=word1.length() ;++i) {
            dist[i].resize(word2.length() + 1);
        }

        for (int i=0; i<=word1.length(); ++i)
        {
            dist[i][0] = i;
        }
        for (int i=0; i<=word2.length(); ++i)
        {
            dist[0][i] = i;
        }
        for (int i=1; i<=word1.length(); ++i)
        {
            for (int j=1; j<=word2.length(); ++j)
            {
                int cost = (word1[i-1] == word2[j-1]) ? 0 : 1;
                dist[i][j] = min(min(dist[i-1][j] + 1, dist[i][j - 1] + 1), dist[i - 1][j - 1] + cost);
            }
        }
        return dist[word1.length()][word2.length()];
    }
};

int main()
{
    Solution s;
    cout << s.minDistance("hello", "eo");
    return 0;
}
