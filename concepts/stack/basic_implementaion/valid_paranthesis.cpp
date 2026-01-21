#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<int> stk;
    for (auto c : s)
    {
        if (c == '(' or c == '[' or c == '{')
        {
            stk.push(c);
        }
        else
        {
            if (stk.empty())
                return false;
            char t = stk.top();
            stk.pop();

            if ((c == ')' and t != '(') or (c == ']' and t != '[') or (c == '}' and t != '{'))
            {
                return false;
            }
        }
    }
    return stk.empty();
}

int main()
{
    string s;
    cin >> s;

    if (isValid(s))
    {
        cout << "valid paranthesis" << endl;
    }
    else
    {
        cout << "invalid paranthesis" << endl;
    }
    return 0;
}
