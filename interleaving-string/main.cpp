#include <string>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
            return false;

        vector<vector<bool> > table(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        
        for (int i=0; i<= s1.length(); ++i)
        {
            for (int j=0; j<=s2.length(); ++j)
            {
                if (i == 0 && j == 0) {
                    table[i][j] = true;
                }
                else if (i == 0) {
                    table[i][j] = table[i][j-1] && s2[j-1] == s3[i+j-1];
                }
                else if (j == 0) {
                    table[i][j] = table[i-1][j] && s1[i-1] == s3[i+j-1];
                }
                else {
                    table[i][j] = table[i][j-1] && s2[j-1] == s3[i+j-1] || table[i-1][j] && s1[i-1] == s3[i+j-1];
                }
            }
        }
        return table[s1.length()][s2.length()];
    }

    bool isInter(const char *s1, const char *s2, const char *s3) {
        int p1 = 0, p2 = 0;
        for (int i=0;s3[i];++i)
        {
            if (s1[p1] == s3[i] &&
                s2[p2] == s3[i]) {
                    if (isInter(s1+p1+1, s2+p2, s3+i+1)) {
                        return true;
                    }
                    if (isInter(s1+p1, s2+p2+1, s3+i+1)) {
                        return true;
                    }
                    return false;
            }
            else if (s1[p1] == s3[i]) {
                p1++;
            }
            else if (s2[p2] == s3[i]) {
                p2++;
            }
            else
                return false;
        }
        return (!s1[p1] && !s2[p2]);
    }
};

int main()
{
    Solution s;
    cout << s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");

    return 0;
}