#include <bits/stdc++.h>
using namespace std;

int grid_paths(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == m && j == n)
        return 1;
    if (i > m || j > n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = grid_paths(i + 1, j, m, n, dp) + grid_paths(i, j + 1, m, n, dp);
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << grid_paths(0, 0, m, n, dp) << endl;
}