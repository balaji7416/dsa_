#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> mx(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
        mx[i] = i;

    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            mx[u] = max(mx[u], mx[v]);
        }
    };
    dfs(dfs, 0, -1);

    for (int i : mx)
        cout
            << i << " ";
    cout << endl;
}