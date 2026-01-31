#include <bits/stdc++.h>
using namespace std;

/*
    dp[i][j] => minimum no.of operations needed to convert s1[0..i] to s2[0..j]
*/

int edit_distance(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    // if s1 empty insert j+1 chars of s2 (since s2 = s2[0...j])
    if (i < 0)
        return j + 1;

    // if s2 empty delete all i+1 chars of s1 (since s1 = s1[0...i])
    if (j < 0)
        return i + 1;

    // if memorized
    if (dp[i][j] != -1)
        return dp[i][j];

    // if chars match no operation
    if (s1[i] == s2[j])
        return dp[i][j] = edit_distance(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = 1 + min(
                              {edit_distance(i, j - 1, s1, s2, dp),     // insert
                               edit_distance(i - 1, j, s1, s2, dp),     // delete
                               edit_distance(i - 1, j - 1, s1, s2, dp)} // replace
                          );
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << edit_distance(n - 1, m - 1, s1, s2, dp);
}