#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<int>> adj;
vector<int> subtree;
vector<int> value;
int dfs(int u, int p)
{

    int child_sbtree = 0;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        child_sbtree += dfs(v, u);
    }
    return subtree[u] = value[u] + child_sbtree;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    int n; // m = n-1 for trees
    cin >> n;
    adj.resize(n);
    subtree.resize(n, 0);
    value.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    for (auto i : subtree)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}