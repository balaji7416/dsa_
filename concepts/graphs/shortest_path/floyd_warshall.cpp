#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = INT_MAX;
int32_t main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
    {
        adj[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u][v] = min(adj[u][v], w);
    }

    vector<vector<int>> dist = adj;
    // run floyd warshall
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] == inf || dist[k][j] == inf)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == inf)
                cout << -1 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}