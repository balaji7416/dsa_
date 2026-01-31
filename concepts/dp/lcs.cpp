#include <bits/stdc++.h>
using namespace std;

/*
    lcs = longest common subsequence
    dp[i][j] = len of lcs subsequence obtainable from a[0...i] and b[0...j]
*/

int lcs(int i, int j, string &a, string &b, vector<vector<int>> &dp)
{
    // base case
    if (i < 0 or j < 0)
    {
        return 0;
    }
    // memorizatin check first
    if (dp[i][j] != -1)
        return dp[i][j];

    // if chars match
    if (a[i] == b[j])
    {
        return dp[i][j] = 1 + lcs(i - 1, j - 1, a, b, dp);
    }

    // if not
    return dp[i][j] = max(
               lcs(i - 1, j, a, b, dp),
               lcs(i, j - 1, a, b, dp));
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    int ans = lcs(a.size() - 1, b.size() - 1, a, b, dp);
    cout << ans << endl;

    return 0;
}