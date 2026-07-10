#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int inf = INT_MAX;
    vector<int> dp(n, -1);
    /*
        dp[i] = min cost to reach last tile from tile i
    */
    auto dfs = [&](auto &&self, int i)
    {
        if (i >= n - 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = min(
                   (i + 1 < n ? (abs(nums[i] - nums[i + 1]) + self(self, i + 1)) : inf),
                   (i + 2 < n ? (abs(nums[i] - nums[i + 2]) + self(self, i + 2)) : inf));
    };

    auto dfs2 = [&]()
    {
        vector<int> dp(n);
        dp[0] = 0, dp[1] = abs(nums[0] - nums[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = min(dp[i - 1] + abs(nums[i] - nums[i - 1]), dp[i - 2] + abs(nums[i] - nums[i - 2]));
        }
        return dp[n - 1];
    };
    // int ans = dfs(dfs, 0);
    int ans = dfs2();
    cout << ans << endl;
    return 0;
}
