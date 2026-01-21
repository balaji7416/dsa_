#include <bits/stdc++.h>
using namespace std;

string manacher(string &s)
{
    string t = "@#";
    for (auto c : s)
    {
        t += c;
        t += "#";
    }
    t += "$";
    int n = t.size();
    vector<int> p(n, 0); // p[i] => radius of palindrome at index i without including the center

    int r = 0, c = 0; // r => right most boundary of the longest palindrome found, c => center of that palindrome
    for (int i = 1; i < n - 1; i++)
    {
        int mirror = 2 * c - i;
        if (i < r)
        {
            p[i] = min(p[mirror], r - i);
        }

        // expand the window
        while (t[i - (p[i] + 1)] == t[i + (p[i] + 1)])
        {
            p[i]++;
        }

        // update r,c
        if (i + p[i] > r)
        {
            r = i + p[i];
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
    string long_palindr_substr = manacher(s);

    cout << long_palindr_substr << endl;
}