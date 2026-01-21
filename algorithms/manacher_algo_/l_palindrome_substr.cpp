#include <bits/stdc++.h>
using namespace std;

string expand(string &s, int l, int r)
{
    int n = s.size();
    while (l >= 0 and r < n and s[l] == s[r])
    {
        l--;
        r++;
    }
    return s.substr(l + 1, r - l - 1);
}

int main()
{
    string s;
    cin >> s;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        // for odd length
        string p1 = expand(s, i, i);
        if (p1.size() > ans.size())
            ans = p1;

        // for even length
        string p2 = expand(s, i, i + 1);
        if (p2.size() > ans.size())
            ans = p2;
    }

    cout << "longest palindrome: " << ans << endl;
}