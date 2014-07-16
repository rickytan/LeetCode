#include <iostream>
#include <string>

using namespace std;


int inter_sum(unsigned long long num) {
    int sign = 1;
    int out = 0;
    while (num) {
        int v = num % 10;
        num /= 10;
        out += sign * v;
        sign = -sign;
    }
    if (sign == -1)
        return out;
    return -out;
}

int main()
{

    unsigned long long l, r, result = 0;
    int k;
    cin >> l >> r >> k;
    for (unsigned long long i=l; i <= r; ++i)
    {
        if (inter_sum(i) == k) {
            result += i;
        }
    }
    cout << result % (1000000007) << endl;
    return 0;
}