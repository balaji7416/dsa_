#include <bits/stdc++.h>
using namespace std;

vector<int> build_lps(string &s)
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

vector<int> build_borders(vector<int> &lps)
{
    int n = lps.size();
    int len = lps[n - 1];
    vector<int> borders;
    while (len > 0)
    {
        borders.push_back(len);
        len = lps[len - 1];
    }
    return borders;
}
int main()
{
    string s;
    cin >> s;
    vector<int> lps = build_lps(s);
    vector<int> borders = build_borders(lps);

    if (borders.size() == 0)
    {
        cout << "no borders " << endl;
    }
    else
    {
        cout << "borders: " << endl;
        for (auto i : borders)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}