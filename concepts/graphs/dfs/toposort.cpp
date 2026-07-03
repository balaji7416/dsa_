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

void topo_sort(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &stk)
{
    visited[node] = true;

    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            topo_sort(neighbor, adj, visited, stk);
        }
    }
    stk.push(node);
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
        cout << "Topo sort order not possible" << endl;
        return 0;
    }
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topo_sort(i, adj, visited, stk);
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}