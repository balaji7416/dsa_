#include <bits/stdc++.h>
using namespace std;

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

    vector<int> inDegree(n, 0);

    for (int u = 0; u < n; u++)
    {
        for (auto v : adj[u])
        {
            inDegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        topo.push_back(u);

        for (auto v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if (topo.size() < n)
    {
        cout << "cycle exists" << endl;
    }
    else
    {
        for (auto x : topo)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}