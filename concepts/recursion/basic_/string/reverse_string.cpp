#include <bits/stdc++.h>
using namespace std;

string reverse_(string s, int l, int r)
{
    if (l >= r)
        return s;
    swap(s[l], s[r]);
    return reverse_(s, l + 1, r - 1);
}

int main()
{
    string s;
    cin >> s;
    s = reverse_(s, 0, s.size() - 1);
    cout << s << endl;
}