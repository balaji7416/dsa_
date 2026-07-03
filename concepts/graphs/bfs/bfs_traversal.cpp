#include <bits/stdc++.h>
using namespace std;

void bfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dist)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    dist[node] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto neighbor : adj[u])
        {
            if (!visited[neighbor])
            {
                dist[neighbor] = dist[u] + 1;
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    vector<int> dist(n, -1);
    bfs(0, adj, visited, dist);
    for (auto i : dist)
    {
        cout << i << " ";
    }
}