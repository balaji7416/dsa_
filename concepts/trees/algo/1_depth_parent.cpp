#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<int>> adj;
vector<int> depth, parent;

void dfs(int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        parent[v] = u;
        depth[v] = 1 + depth[u];
        dfs(v, u);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    parent.resize(n, -1);
    depth.resize(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // u--;
        // v--;

        // trees are undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);

    for (auto i : depth)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto p : parent)
    {
        cout << p << " ";
    }
    cout << endl;
    return 0;
}