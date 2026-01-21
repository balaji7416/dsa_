#include <bits/stdc++.h>
using namespace std;

string manacher(string &s)
{
    string t = "@#";
    for (auto i : s)
    {
        t += i;
        t += "#";
    }
    t += "$";
    int n = t.size();
    vector<int> p(n, 0);
    int r = 0, c = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int mirror = 2 * c - i;
        if (i < r)
        {
            p[i] = min(p[mirror], r - i);
        }

        while (t[i + (1 + p[i])] == t[i - (p[i] + 1)])
        {
            p[i]++;
        }

        if (p[i] + i > r)
        {
            r = p[i] + i;
            c = i;
        }
    }
    int maxLen = 0, centerIdx = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (p[i] > maxLen)
        {
            maxLen = p[i];
            centerIdx = i;
        }
    }

    int start = (centerIdx - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main()
{
    string s;
    cin >> s;
    cout << manacher(s) << endl;
}