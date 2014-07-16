#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string str;
    while (std::getline(cin, str)) {
        int count[256] = {0};
        bool error = false;
        for (int i=0;i<str.length();++i)
        {
            char ch = str[i];
            if (ch < '0' ||
                '9' < ch && ch < 'a' ||
                ch > 'z') {
                cout << "<invalid input string>" << endl;
                error = true;
                break;
            }
            count[ch]++;
        }

        if (!error) {
            string out = "";
            int length = str.length();
            while (length) {
                string tmp = "";
                for (char i='0';i<='9';++i)
                {
                    if (count[i]) {
                        tmp += i;
                        count[i]--;
                        length--;
                    }
                }
                for (char i='a';i<='z';++i)
                {
                    if (count[i]) {
                        tmp += i;
                        count[i]--;
                        length--;
                    }
                }
                out = out + tmp;
            }
            cout << out << endl;
        }
    }
    return 0;
}