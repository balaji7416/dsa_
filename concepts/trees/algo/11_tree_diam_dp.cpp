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

    int diam = 0;
    auto dfs = [&](auto &&self, int u, int p) -> int
    {
        int mx1 = 0, mx2 = 0;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            int h = self(self, v, u);
            if (h > mx1)
            {
                mx2 = mx1;
                mx1 = h;
            }
            else if (h > mx2)
            {
                mx2 = h;
            }
        }
        diam = max(diam, mx1 + mx2);
        return 1 + mx1;
    };

    dfs(dfs, 0, -1);
    cout << diam << endl;
}