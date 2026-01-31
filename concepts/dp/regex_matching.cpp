#include <bits/stdc++.h>
using namespace std;

/*
    f(i,j) => does string s[i:] match p[j:]
    in regex:
        . => matches any char
        * => matches previous char any number of times (including zero)
    base cases:
        if(pattern ends) for a match string should also end

*/

/*
    dp[i][j] => does the string s[i..n-1] matches pattern p[j..m-1] follwing the given notation constraints

*/

bool regex_match(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{

    // if pattern ends
    if (j == p.size())
    {
        return i == s.size();
    }

    // if memorized
    if (dp[i][j] != -1)
        return dp[i][j];

    // check first match
    bool first_match = i < s.size() && (s[i] == p[j] || p[j] == '.');

    // if the next char in pattern is *
    if (j + 1 < p.size() && p[j + 1] == '*')
    {
        // take zero instance of the current char in pattern f(i,j+2)
        bool skip = regex_match(i, j + 2, s, p, dp);

        // if first char matched then use this current char to match more chars in string if possible
        bool include = first_match && regex_match(i + 1, j, s, p, dp);

        return dp[i][j] = skip || include;
    }

    // if the next char in pattern is not *
    if (first_match)
    {
        return dp[i][j] = regex_match(i + 1, j + 1, s, p, dp);
    }

    // if current chars don't match
    return dp[i][j] = false;
}

int main()
{
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    bool is_match = regex_match(0, 0, s, p, dp);

    cout << dp[n][m] << endl;

    is_match ? cout << "matched" : cout << "no match" << endl;
}