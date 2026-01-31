#include <bits/stdc++.h>
using namespace std;

string remove_substr(string &s, string &r, int i)
{
    int n = s.size();
    if (i >= n)
    {
        return "";
    }
    if (s.substr(i, r.size()) == r)
    {
        return remove_substr(s, r, i + r.size());
    }
    else
    {
        return s[i] + remove_substr(s, r, i + 1);
    }
}

int main()
{
    string s, r;
    cin >> s >> r;
    s = remove_substr(s, r, 0);
    cout << s << endl;
}