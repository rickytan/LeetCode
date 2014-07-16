#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int totalNum(int N, int M)
{
    int sum = N + M;
    if (N > M) {
        int t = N;
        N = M;
        M = t;
    }
    int total = 1;
    for (int i = sum; i>M; --i)
    {
        total *= i;
    }
    for (int i=2; i<=N; ++i)
    {
        total /= i;
    }
    return total;
}

class Solution {
public:
    void nextPermutation(string &num) {
        for (int i=num.size()-1;i>0;--i)
        {
            if (num[i] > num[i-1]) {
                int j=0;
                for (j=i;j<num.size();++j) {
                    if (num[j]<=num[i-1])
                        break;
                }
                std::swap(num[j-1], num[i-1]);
                std::sort(num.begin()+i, num.end());
                return;
            }
        }
        std::reverse(num.begin(), num.end());
    }
};

int main()
{
    int t = 0;
    cin >> t;
    for (int c = 0;c < t;++c)
    {
        int N, M, K;
        cin >> N >> M >> K;
        if (K > totalNum(N, M)) {
            cout << "Impossible" << endl;
        }
        else {
            Solution s;
            string str = "";
            str.append(N, '0');
            str.append(M, '1');
            for (int i=0;i<K-1;++i) {
                s.nextPermutation(str);
            }

            cout << str << endl;
        }
    }
    return 0;
}