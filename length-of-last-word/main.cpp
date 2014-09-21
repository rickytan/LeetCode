#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string ss(s);
        ss.erase(ss.find_last_not_of(" ") + 1);
        size_t pos = ss.rfind(" ");
        if (pos == string::npos)
            return ss.size();;
        return ss.size() - pos - 1;
    }
};

int main() {

    return 0;
}