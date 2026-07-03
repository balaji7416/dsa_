#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    const int inf = 1e9;

    vector<vector<int>> adj(n, vector<int>(n, inf));

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    vector<int> dist(n, inf);
    vector<bool> visited(n, false);
    dist[0] = 0; // dist from src to src = 0

    for (int i = 0; i < n; i++)
    {

        // find the nearest unvisited node to src
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
            break; // reamining nodes are not reachable
        }

        visited[u] = true; // finalize this node's shortest distance

        // relax other distances through this node
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && adj[u][v] != inf)
            {
                dist[v] = min(dist[v], dist[u] + adj[u][v]);
            }
        }
    }

    for (int d : dist)
        cout << d << " ";
    cout << endl;
}