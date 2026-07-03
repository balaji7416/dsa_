#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &inRec, vector<bool> &visited)
{
    visited[node] = true;
    inRec[node] = true;
    stack<int> stk;
    stk.push(node);
    while (!stk.empty())
    {
        auto u = stk.top();
        stk.pop();
        for (auto neighbor : adj[u])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                inRec[neighbor] = true;
                stk.push(neighbor);
            }
            else if (inRec[neighbor])
            {
                return true;
            }
        }
        // backtrack
        inRec[u] = false;
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
        // adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    vector<bool> inRec(n, false);
    bool isCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, inRec, visited))
            {
                isCycle = true;
                break;
            }
        }
    }
    isCycle ? cout << "Cycle found" << endl : cout << "no Cycle found damn it..." << endl;
}