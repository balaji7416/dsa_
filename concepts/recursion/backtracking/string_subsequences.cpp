#include <bits/stdc++.h>
using namespace std;

void generate(string &s, string curr, int i)
{
    // base case
    if (i == s.size())
    {
        cout << curr << " ";
        return;
    }

    // choose the char at index i and recurse
    generate(s, curr + s[i], i + 1);

    // don't choose the char at index i and recurse
    generate(s, curr, i + 1);
}

int main()
{
    string s;
    cin >> s;
    generate(s, "", 0);
}