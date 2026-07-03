#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto prims = [&]()
    {
        vector<bool> inMst(n, false);
        vector<int> dist(n, INT_MAX); // min dist from a node to any node in mst

        dist[0] = 0;
        int cst = 0;
        for (int i = 0; i < n; i++)
        {
            // 1. find the node with min dist from mst that is not in mst
            int u = -1;
            for (int j = 0; j < n; j++)
            {
                if (!inMst[j] && (u == -1 || dist[j] < dist[u]))
                {
                    u = j;
                }
            }

            // 2. add it to mst
            if (u == -1)
                break;

            inMst[u] = true;
            cst += dist[u];

            // 3. update dist of adjacent nodes
            for (auto &[v, w] : adj[u])
            {
                if (!inMst[v])
                {
                    dist[v] = min(dist[v], w);
                }
            }
        }
        return cst;
    };

    auto dikstras = [&](int src)
    {
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[src] = 0;
        for (int i = 0; i < n; i++)
        {
            // 1. find the min dist unvisited node to src
            int u = -1;
            for (int j = 0; j < n; j++)
            {
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                {
                    u = j;
                }
            }

            if (u == -1 || dist[u] == INT_MAX)
                break; // no more nodes to visit

            // 2. mark it visited (finalize the distance to node u from src)
            visited[u] = true;

            // 3. update dist of adjacent nodes
            for (auto &[v, w] : adj[u])
            {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
        return dist;
    };
    cout << prims()
         << endl;

    auto dist = dikstras(0);
    for (auto i : dist)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}