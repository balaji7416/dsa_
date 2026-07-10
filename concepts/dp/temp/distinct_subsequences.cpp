#include <bits/stdc++.h>
using namespace std;

/*
    f(i,j) => no.of distinct subsequences in s[i:] that match target string t[j:]
    base cases:
        if target becomes empty i.e, j == target.size():
            return 1 (sicne we have matched the whole target)
        if s becomes empty and target doesn't i.e., i == s.size():
            return 0 (since we can't match target anymore)
*/

int distinct_subseqs(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{

    // if target becomes empty
    if (j == t.size())
    {
        return 1;
    }

    // if string becomes empty
    if (i == s.size())
    {
        return 0;
    }

    // if memorized
    if (dp[i][j] != -1)
        return dp[i][j];

    int ways = distinct_subseqs(i + 1, j, s, t, dp); // skip the curr char in s[i:]
    if (s[i] == t[j])
    {
        ways += distinct_subseqs(i + 1, j + 1, s, t, dp); // consider the curr char in s[i:] if s[i] == t[j]
    }
    return dp[i][j] = ways;
}

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = distinct_subseqs(0, 0, s, t, dp);
    cout << ans << endl;
}