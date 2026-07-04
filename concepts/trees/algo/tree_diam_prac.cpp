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

    auto dfs = [&](auto &&self, int u, int p, int dist) -> pair<int, int>
    {
        pair<int, int> best = {dist, u};
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            best = max(best, self(self, v, u, dist + 1));
        }
        return best;
    };
    auto [_, e1] = dfs(dfs, 0, -1, 0);
    auto [diam, e2] = dfs(dfs, e1, -1, 0);

    cout << diam << endl;
}