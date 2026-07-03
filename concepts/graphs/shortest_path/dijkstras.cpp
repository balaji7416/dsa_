#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
vector<int> dijkstras(int src, vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, inf);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (w > dist[u])
            continue;

        for (auto [v, wgt] : adj[u])
        {
            if (dist[u] + wgt < dist[v])
            {
                dist[v] = dist[u] + wgt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<int> shrt_dist = dijkstras(0, adj);
    for (int i = 0; i < shrt_dist.size(); i++)
    {
        cout << shrt_dist[i] << " ";
    }
    cout << endl;
}