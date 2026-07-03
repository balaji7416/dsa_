#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, node, adj, visited))
            {
                return true;
            }
        }
        else if (neighbor != parent)
        {
            return true;
        }
    }
    return false;
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

    auto dfs_ = [&](auto &&self, int u, int p)
    {
        visited[u] = true;
        for (int v : adj[u])
        {
            if (visited[v] && v != p)
                return true; // cycle found
            if (visited[v] && v == p)
                continue;
            if (self(self, v, u))
                return true;
        }
        return false;
    };

    bool hasCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj, visited))
            {
                hasCycle = true;
                break;
            }
        }
    }
    if (hasCycle)
    {
        cout << "Cycle Exists" << endl;
    }
    else
    {
        cout << "No Cycle Exists" << endl;
    }
}