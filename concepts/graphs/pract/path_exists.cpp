#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, int dest, vector<vector<int>> &adj, vector<bool> &visited)
{
    if (src == dest)
    {
        return true;
    }
    visited[src] = true;
    for (auto neighbor : adj[src])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, dest, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int src, dest;
    cin >> src >> dest;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);

    auto dfs_ = [&](auto &&self, int u)
    {
        if (u == dest)
            return true;
        visited[u] = true;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                if (self(self, v))
                    return true;
            }
        }
        return false;
    };

    if (dfs_(dfs_, src))
    {
        cout << "path exists" << endl;
    }
    else
    {
        cout << "no path found" << endl;
    }
}