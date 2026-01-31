#include <bits/stdc++.h>
using namespace std;

/*
    f(i,j) => is string s[i...n-1] match pattern s[j...m-1]
    base cases:
        if(string becomes empty) then all remaining chars of pattern should be *, so that they act as empty
        if(pattern becomes empty and string doesn't) then string can't match pattern
        if(match or p[j] == '?') move to match s[i+1...n-1] and p[j+1...m-1]
*/
/*
    dp[i][j] => is string s[i...n-1] match with p[j...m-1]
*/

bool wild_card_match(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{

    // if string ends while pattern doesn't
    if (i >= s.size())
    {
        for (int k = j; k < p.size(); k++)
        {
            if (p[k] != '*')
                return false;
        }
        return true;
    }

    // if pattern ends while string doesn't
    if (j >= p.size())
    {
        return false;
    }

    // if memorized
    if (dp[i][j] != -1)
        return dp[i][j];

    // if char match or p[j] == '?'
    if (s[i] == p[j] || p[j] == '?')
    {
        return dp[i][j] = wild_card_match(i + 1, j + 1, s, p, dp);
    }

    // if p[j] = '*'
    if (p[j] == '*')
    {
        return dp[i][j] = wild_card_match(i + 1, j, s, p, dp) || wild_card_match(i, j + 1, s, p, dp);
        // match one or more chars         match nothing
    }

    // if s[i] != p[j]
    return dp[i][j] = false;
}

int main()
{
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    bool isMatch = wild_card_match(0, 0, s, p, dp);

    isMatch ? cout << "matched" << endl : cout << "no match" << endl;
}