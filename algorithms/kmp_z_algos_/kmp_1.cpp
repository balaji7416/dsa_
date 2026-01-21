#include <bits/stdc++.h>
using namespace std;

vector<int> build_lps(string &p)
{
    int m = p.size();
    int i = 1, len = 0;
    vector<int> lps(m, 0);
    while (i < m)
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
    int n = t.size();
    int m = p.size();
    vector<int> lps = build_lps(p);
    vector<int> result;
    int i = 0, j = 0;
    while (i < n)
    {
        if (t[i] == p[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            result.push_back(i - m);
            j = lps[j - 1];
        }
        else if (i < n and t[i] != p[j])
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
    vector<int> result = kmp(t, p);

    if (result.empty())
    {
        cout << "pattern not found in the text" << endl;
    }
    else
    {
        cout << "pattern found at indices: " << endl;
        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}