#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string a = "abc";
    std::reverse(a.begin(), a.end());
    string str;
    while (std::getline(cin, str)) {
        cout << str << endl;
        std::istringstream is(str);
        string word;
        while (is >> word)
            cout << word << endl;
    }
    
    return 0;
}