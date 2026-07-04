#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> depth(n, 0), parent(n, -1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            parent[v] = u;
            depth[v] = 1 + depth[u];
            self(self, v, u);
        }
    };

    dfs(dfs, 0, -1);

    for (int i : depth)
        cout << i << " ";
    cout << endl;
    for (int i : parent)
        cout << i << " ";
    cout << endl;
    return 0;
}