#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        nums.push_back({a, b, c});
    }
    /*
        dp[i] = max happiness starting from day i if we choose activity t on this day
    */
    vector<vector<int>> dp(n, vector<int>(3, -1));
    auto dfs = [&](auto &&self, int i, int t) -> int
    {
        if (i >= n)
            return 0;
        if (dp[i][t] != -1)
            return dp[i][t];
        return dp[i][t] = nums[i][t] + max(self(self, i + 1, (t - 1 + 3) % 3), self(self, i + 1, (t + 1) % 3));
    };
    auto dfs2 = [&]() -> int
    {
        /*
            dp[i][t] => max happiness from day 0 to day i when t'th activity is chosen on day i
        */
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = nums[0][0], dp[0][1] = nums[0][1], dp[0][2] = nums[0][2];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = nums[i][j] + max(dp[i - 1][(j - 1 + 3) % 3], dp[i - 1][(j + 1) % 3]);
            }
        }
        return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    };
    // int ans = max({dfs(dfs, 0, 0), dfs(dfs, 0, 1), dfs(dfs, 0, 2)});
    int ans = dfs2();
    cout << ans << endl;
}