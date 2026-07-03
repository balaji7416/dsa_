#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion)
{
    visited[node] = true;
    inRecursion[node] = true;

    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, adj, visited, inRecursion))
            {
                return true;
            }
        }
        else if (inRecursion[neighbor])
        {
            return true;
        }
    }
    inRecursion[node] = false;
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
    }

    vector<bool> visited(n, false);
    vector<bool> inRecursion(n, false);

    auto dfs_ = [&](auto &&self, int u)
    {
        visited[u] = true;
        inRecursion[u] = true;
        for (int v : adj[u])
        {
            if (inRecursion[v])
                return true;
            if (visited[v])
                continue;
            if (self(self, v))
                return true;
        }
        inRecursion[u] = false;
        return false;
    };

    bool hasCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, inRecursion))
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