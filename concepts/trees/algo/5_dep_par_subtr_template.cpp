#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent, depth, subtree;

int dfs(int u, int p)
{
    int child_subtree = 0;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        child_subtree += dfs(v, u);
    }
    return subtree[u] = 1 + child_subtree;
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n);
    parent.resize(n, -1);
    subtree.resize(n, 0);
    depth.resize(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    // parent
    for (auto p : parent)
    {
        cout << p << " ";
    }
    cout << endl;

    // depth
    for (auto d : depth)
    {
        cout << d << " ";
    }
    cout << endl;

    // subtree size
    for (auto s : subtree)
    {
        cout << s << " ";
    }
    cout << endl;
}