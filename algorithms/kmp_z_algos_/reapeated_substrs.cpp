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

int main()
{
    string s;
    cin >> s;
    vector<int> lps = build_lps(s);
    int n = s.size();
    int len = lps[n - 1];
    if (len > 0 and n % (n - lps[n - 1]) == 0)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}