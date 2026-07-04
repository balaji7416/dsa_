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
    int LOG = 20;
    vector<int> depth(n, 0);
    vector<vector<int>> up(n, vector<int>(LOG, -1));

    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        up[u][0] = p;

        for (int i = 1; i < LOG; i++)
        {
            up[u][i] = up[u][i - 1] == -1 ? -1 : up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u])
        {
            if (v == p)
                continue;
            depth[v] = depth[u] + 1;
            self(self, v, u);
        }
    };

    dfs(dfs, 0, -1);

    auto jump = [&](int x, int k)
    {
        for (int i = 0; i < LOG; i++)
        {
            if (k & (1 << i))
            {
                x = up[x][i];
                if (x == -1)
                    return -1;
            }
        }
        return x;
    };

    auto lca = [&](int a, int b)
    {
        if (depth[a] < depth[b])
            swap(a, b);

        // equilize the depth
        a = jump(a, depth[a] - depth[b]);

        if (a == b)
            return a;

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (up[a][i] != -1 && up[b][i] != -1 && up[a][i] != up[b][i])
            {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    };

    return 0;
}