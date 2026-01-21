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

string sp(string &s)
{
    int n = s.size();
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string new_s = s + "#" + rev_s;
    vector<int> lps = build_lps(new_s);

    int len = lps.back();
    string add = s.substr(len);
    reverse(add.begin(), add.end());

    return add + s;
}

int main()
{
    string s;
    cin >> s;
    string shortest_palindrome = sp(s);

    cout << shortest_palindrome << endl;
}