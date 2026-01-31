#include <bits/stdc++.h>
using namespace std;

/*
    lps = longest palindromic subsequnce
    dp[i][j] = len of lps that can be obtained from s[i....j];
    interval dp
*/

int lps(int i, int j, string &s, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        return 1;
    }
    // check if memorized
    if (dp[i][j] != -1)
        return dp[i][j];

    // if chars match
    if (s[i] == s[j])
    {
        return dp[i][j] = 2 + lps(i + 1, j - 1, s, dp);
    }

    // if not

    return dp[i][j] = max(lps(i + 1, j, s, dp),
                          lps(i, j - 1, s, dp));
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int len = lps(0, n - 1, s, dp);

    string ans = "";
    string temp = "";
    int i = 0, j = n - 1;
    while (i < n and j >= 0 && i <= j)
    {
        if (s[i] == s[j])
        {
            if (i != j)
                temp += s[i];
            ans += s[i];
            i++;
            j--;
        }
        else if (j > 0 && dp[i][j] == dp[i][j - 1])
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    reverse(temp.begin(), temp.end());
    ans += temp;
    cout << ans << endl;
    cout << len << endl;
}