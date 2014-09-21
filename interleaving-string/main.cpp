#include <string>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int p1 = 0, p2 = 0;
        stack<int> rewind1;
        stack<int> rewind2;
        for (int i=0; i<s3.length() ;++i)
        {
            if (s1[p1] == s3[i] &&
                s2[p2] == s3[i]) {
                rewind1.push(p1);
                rewind2.push(p2);
                p1++;
            }
            else if (s1[p1] == s3[i]) {
                p1++;
            }
            else if (s2[p2] == s3[i]) {
                p2++;
            }
            else {
                return false;
            }
        }
        return isInter(s1.c_str(), s2.c_str(), s3.c_str());
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