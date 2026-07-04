#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<int>> adj;

pair<int, int> dfs(int u, int p, int dist)
{
    pair<int, int> best = {dist, u};
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        best = max(best, dfs(v, u, dist + 1));
    }
    return best;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    adj.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto [_, e1] = dfs(0, -1, 0);
    auto [diameter, e2] = dfs(e1, -1, 0);

    cout << diameter << endl;
    return 0;
}