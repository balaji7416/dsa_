#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i].first >> nums[i].second;
    }
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    /*
        dp[i][wt] = max value that can be obtained from item i to item n with current weight holding as wt
    */
    auto dfs = [&](auto &&self, int i, int wt) -> int
    {
        if (i >= n)
            return 0;
        if (dp[i][wt] != -1)
            return dp[i][wt];

        int ans = self(self, i + 1, wt);
        if (wt + nums[i].first <= w)
        {
            ans = max(ans, nums[i].second + self(self, i + 1, wt + nums[i].first));
        }

        return dp[i][wt] = ans;
    };
    auto dfs2 = [&]()
    {
        /*
            dp[i][w] = max value obtainable from item i to itme n-1 with current weight as w
        */
        vector<vector<int>> dp(n + 1, vector<int>(w + 1));

        // base case: if item is out of bound, no value
        for (int wt = 0; wt <= w; wt++)
            dp[n][wt] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int wt = 0; wt <= w; wt++)
            {
                // skip
                dp[i][wt] = dp[i + 1][wt];

                if (wt + nums[i].first <= w)
                {
                    dp[i][wt] = max(dp[i][wt], nums[i].second + dp[i + 1][wt + nums[i].first]);
                }
            }
        }
        return dp[0][0];
    };
    // int ans = dfs(dfs, 0, 0);
    int ans = dfs2();
    cout << ans << endl;
}