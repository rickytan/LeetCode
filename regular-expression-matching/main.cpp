#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    typedef struct _State {
        struct _State *addPath(char path, struct _State *next = NULL) {
            if (next == NULL && pathes.count(path) == 0)
                next = new struct _State();
            else if (next == NULL)
                next = pathes[path];
            pathes[path] = next;
            return next;
        }

        map<char, _State *> pathes;
    } State;

    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL ||
            *s == 0 && *p == 0)
            return true;
        if (p == NULL || s == NULL || *p == 0 || *s == 0)
            return false;

        State start, *end;
        State *curr_state = &start;
        char last = *p++, curr = *p;
        while (*p) {

            if (curr == '*') {
                if (last != '*')
                    curr_state = curr_state->addPath(last, curr_state);
            }
            else {
                if (last != '*')
                    curr_state = curr_state->addPath(last);
            }
            ++p;
            last = curr;
            curr = *p;
        }
        if (last != '*')
            curr_state = curr_state->addPath(last);
        end = curr_state;

        curr_state = &start;
        while (*s) {
            if (curr_state->pathes.count(*s)) {
                curr_state = curr_state->pathes[*s];
            }
            else if (curr_state->pathes.count('.')) {
                curr_state = curr_state->pathes['.'];
            }
            else
                return false;
            s++;
        }
        return curr_state == end;
    }
};

int main()
{
    Solution s;
    cout << s.isMatch("aaa", "a*a");
    return 0;
}
