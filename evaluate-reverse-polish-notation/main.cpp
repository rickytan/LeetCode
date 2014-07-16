#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> token_stack;
        for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
        {
            if (it->length() == 1) {
                switch ((*it)[0])
                {
                case '+':
                    {
                        int b = token_stack.top();
                        token_stack.pop();
                        int a = token_stack.top();
                        token_stack.pop();
                        token_stack.push(a + b);
                    }
                    break;
                case '-':
                    {
                        int b = token_stack.top();
                        token_stack.pop();
                        int a = token_stack.top();
                        token_stack.pop();
                        token_stack.push(a - b);
                    }
                    break;
                case '*':
                    {
                        int b = token_stack.top();
                        token_stack.pop();
                        int a = token_stack.top();
                        token_stack.pop();
                        token_stack.push(a * b);
                    }
                    break;
                case '/':
                    {
                        int b = token_stack.top();
                        token_stack.pop();
                        int a = token_stack.top();
                        token_stack.pop();
                        token_stack.push(a / b);
                    }
                    break;

                default:
                    token_stack.push(atoi(it->c_str()));
                    break;
                }
            }
            else {
                token_stack.push(atoi(it->c_str()));
            }
        }
        return token_stack.top();
    }
};

int main()
{
    Solution s;
    vector<string> v;
    v.push_back("-1");
    v.push_back("1");
    v.push_back("*");
    v.push_back("-1");
    v.push_back("+");
    cout << s.evalRPN(v);
    return 0;
}