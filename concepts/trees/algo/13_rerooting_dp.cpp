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

    vector<int> sz(n, 0);
    vector<int> dp(n, 0);
    auto dfs1 = [&](auto &&self, int u, int p) -> void
    {
        sz[u] = 1;
        dp[u] = 0;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);

            sz[u] += sz[v];
            dp[u] += dp[v] + sz[v];
        }
    };

    auto dfs2 = [&](auto &&self, int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dp[v] = dp[u] - sz[v] + n - sz[v];
            self(self, v, u);
        }
    };
    dfs1(dfs1, 0, -1);
    dfs2(dfs2, 0, -1);

    for (int i : dp)
        cout << i << " ";
    cout << endl;
    return 0;
}