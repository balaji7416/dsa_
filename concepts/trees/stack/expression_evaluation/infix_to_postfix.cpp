#include <bits/stdc++.h>
using namespace std;

bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 0;
    else if (c == '*' || c == '/')
        return 1;
    return -1;
}
string convert_to_postfix(string s)
{
    string ans = "";
    stack<char> stk;
    for (auto c : s)
    {
        if (c == '(')
        {
            stk.push(c);
        }
        else if (c == ')')
        {
            while (!stk.empty() and stk.top() != '(')
            {
                char t = stk.top();
                stk.pop();
                ans += t;
            }
            if (!stk.empty() && stk.top() == '(')
                stk.pop();
        }
        else if (is_operator(c))
        {
            while (!stk.empty() && stk.top() != '(' && precedence(c) <= precedence(stk.top()))
            {
                char t = stk.top();
                stk.pop();
                ans += t;
            }
            stk.push(c);
        }
        else
        {
            ans += c;
        }
    }
    while (!stk.empty())
    {
        char t = stk.top();
        stk.pop();
        ans += t;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    string postfix = convert_to_postfix(s);
    cout << postfix << endl;

    return 0;
}