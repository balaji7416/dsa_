#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    cout << node << " ";
    visited[node] = true;
    for (auto n : adj[node])
    {
        if (!visited[n])
        {
            dfs(n, adj, visited);
        }
    }
}

void dfs_iterative(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    stack<int> stk;
    stk.push(node);
    visited[node] = true;

    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();

        cout << u << " ";
        for (int i = adj[u].size() - 1; i >= 0; i--)
        {
            int neighbor = adj[u][i];
            if (!visited[neighbor])
            {
                stk.push(neighbor);
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
    dfs_iterative(0, adj, visited);
    cout << endl;
}