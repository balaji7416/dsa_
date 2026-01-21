#include <bits/stdc++.h>
using namespace std;

vector<int> build_lps(string s)
{
    int m = s.size();
    vector<int> lps(m, 0);
    int i = 1, len = 0;
    while (i < m)
    {
        if (s[i] == s[len])
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

bool kmp(string t, string p)
{
    if (p.size() == 0)
        return false;

    vector<int> lps = build_lps(p);
    int n = t.size(), m = p.size();
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
            return true;
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
    return false;
}

int main()
{

    // check if b is rotation of a
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size())
    {
        cout << "no" << endl;
        return 0;
    }

    if (kmp(a + a, b))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}