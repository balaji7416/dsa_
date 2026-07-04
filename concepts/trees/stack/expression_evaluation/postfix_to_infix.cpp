#include <bits/stdc++.h>
using namespace std;

bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string convert_to_infix(string s)
{
    stack<string> stk;
    for (auto c : s)
    {
        if (is_operator(c))
        {
            string b = stk.top();
            stk.pop();
            string a = stk.top();
            stk.pop();
            string expres = "(" + a + c + b + ")";
            stk.push(expres);
        }
        else
        {
            stk.push(string(1, c));
        }
    }
    return stk.top();
}

int main()
{
    string s;
    cin >> s;
    string infix = convert_to_infix(s);
    cout << infix << endl;
    return 0;
}