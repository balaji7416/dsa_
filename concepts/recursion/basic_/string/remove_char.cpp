#include <bits/stdc++.h>
using namespace std;

string removeAll(string &s, char c, int i)
{
    int n = s.size();
    if (i == n)
        return "";
    string res = removeAll(s, c, i + 1);
    if (s[i] != c)
    {
        res.insert(res.begin(), s[i]);
    }
    return res;
}

int main()
{
    string s;
    char c;
    cin >> s >> c;
    s = removeAll(s, c, 0);
    cout << s << endl;
}