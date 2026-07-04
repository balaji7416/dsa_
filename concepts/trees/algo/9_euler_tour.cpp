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

    vector<int> tin(n, 0), sz(n, 0), flat(n, 0);
    int timer = 0;
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        tin[u] = timer;
        flat[timer] = u;
        timer++;

        sz[u] = 1;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0, -1);

    cout << "tin: ";
    for (auto i : tin)
        cout << i << " ";
    cout << endl;
    cout << "sz: ";
    for (auto i : sz)
        cout << i << " ";
    cout << endl;
    cout << "flat: ";
    for (auto i : flat)
        cout << i + 1 << " ";
    cout << endl;

    /*
        range of subtree of node u : [tin[u], tin[u]+sz[u]-1]
    */
}