#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, inf));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    vector<int> visited(n, false);
    vector<int> dist(n, inf);
    dist[0] = 0;

    for (int i = 0; i < n; i++)
    {

        // find the min not visited node
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        if (u == -1 || dist[u] == inf)
        {
            break;
        }

        visited[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && adj[u][v] != inf)
            {
                dist[v] = min(dist[v], dist[u] + adj[u][v]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}