#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (string::iterator it=s.begin(); it!= s.end(); ++it)
        {
            char ch = *it;
            char top = 0;
            if (!st.empty())
                top = st.top();
            switch (ch)
            {
            case '(':case '{':case '[':
                st.push(ch);
                break;
            case ')':
                if (!top) return false;
                if (top == '(')
                    st.pop();
                break;
            case '}':
                if (!top) return false;
                if (top == '{')
                    st.pop();
                break;
            case ']':
                if (!top) return false;
                if (top == '[')
                    st.pop();
                break;
            default:
                break;
            }
        }
    
        return st.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid("([)]");
}