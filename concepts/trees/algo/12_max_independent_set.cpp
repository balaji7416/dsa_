#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n, vector<int>(2, 0));
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        dp[u][0] = 0; // not take node u
        dp[u][1] = 1; // take node u

        for (int v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);

            // if you didn't took node u, then you can either take or not take it's children
            dp[u][0] += max(dp[v][0], dp[v][1]);

            // if you took node u, you can't take it's children
            dp[u][1] += dp[v][0];
        }
    };
    dfs(dfs, 0, -1);
    cout << max(dp[0][1], dp[0][0]) << endl;
    return 0;
}