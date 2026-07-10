#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n, w;
    cin >> n >> w;
    vector<int> val(n), wt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    int tv = accumulate(val.begin(), val.end(), 0);
    vector<vector<int>> dp(n, vector<int>(tv + 1, -1));
    /*
        dp[i][v] = min capacity required to obtain value v from item i to item n-1
    */
    const int INF = 1e9;
    auto dfs = [&](auto &&self, int i, int v) -> int
    {
        if (i >= n)
        {
            if (v == 0)
                return 0;
            return INF;
        }
        if (dp[i][v] != -1)
            return dp[i][v];
        int cap = self(self, i + 1, v);
        if (v - val[i] >= 0)
        {
            cap = min(cap, wt[i] + self(self, i + 1, v - val[i]));
        }
        return dp[i][v] = cap;
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= tv; j++)
        {
            if (dfs(dfs, i, j) <= w)
            {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}