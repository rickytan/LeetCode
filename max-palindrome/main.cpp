#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string insert_spaces(const string &str) {
    int length = str.length();
    string new_str;
    new_str.reserve(length * 2 + 2);
    new_str.append("^");
    string part = " 0";
    for (int i=0; i < length; ++i)
    {
        part[1] = str[i];
        new_str.append(part);
    }
    new_str.append(" ");
    return new_str;
}

int main()
{
    vector<int> cache;
    string str;
    int N;
    cin >> N;
    while (N--) {
        cin >> str;
        str = insert_spaces(str);
    
        vector<int> p(str.length());
        int mx = 0, id = 0;
        for (int i = 1; str[i] != '\0'; i++) {
            p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
            while (str[i + p[i]] == str[i - p[i]])
                p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        cout << *std::max_element(p.begin(), p.end()) - 1 << endl;
    }
    return 0;
}