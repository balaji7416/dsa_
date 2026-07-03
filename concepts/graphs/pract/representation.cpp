#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adj list
    vector<vector<int>> adj(n);

    // adj weighted list
    // vector<vector<pair<int,int>> adj(n); // {v,w} -> v -> neighbour, w -> weight

    // adj matrix
    //  vector<vector<int>> adj(n,vector<int>(n,0));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);

        // undirected
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}