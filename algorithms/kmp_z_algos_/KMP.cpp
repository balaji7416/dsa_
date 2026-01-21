#include <bits/stdc++.h>
using namespace std;

vector<int> build_lps(string p)
{
    int n = p.size();
    vector<int> lps(n, 0);
    int i = 1, len = 0;
    while (i < n)
    {
        if (p[i] == p[len])
        {
            lps[i] = ++len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmp(string &t, string &p)
{
    if (p.size() == 0)
        return {};
    int m = t.size(), n = p.size();
    int i = 0, j = 0;
    vector<int> result;
    vector<int> lps = build_lps(p);
    while (i < m)
    {
        if (t[i] == p[j])
        {
            i++;
            j++;
        }
        if (j == n)
        {
            result.push_back(i - n);
            j = lps[j - 1];
        }
        else if (i < m and t[i] != p[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return result;
}

int main()
{
    string t, p;
    cin >> t >> p;
    vector<int> matches = kmp(t, p);

    if (matches.size() == 0)
    {
        cout << "pattern not found in text" << endl;
    }
    else
    {
        cout << "pattern found " << matches.size() << " times" << endl;
        for (auto i : matches)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}