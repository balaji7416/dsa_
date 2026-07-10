#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int inf = 1e9;
    auto dfs1 = [&]()
    {
        vector<int> dp(n);
        /*
            dp[i] = min cost to reach tile i from tile 0
        */
        dp[0] = 0;
        dp[1] = abs(nums[0] - nums[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = inf;
            for (int j = max(0, i - k); j < i; j++)
            {
                dp[i] = min(dp[i], dp[j] + abs(nums[i] - nums[j]));
            }
        }
        return dp[n - 1];
    };
    int ans = dfs1();
    cout << ans << endl;
    return 0;
}