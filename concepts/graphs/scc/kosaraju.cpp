#include <bits/stdc++.h>
using namespace std;

// struct kosaraju
// {
//     int n;
//     vector<vector<int>> adj, radj, scc;
//     vector<int> order, comp;
//     vector<bool> visited;

//     kosaraju(int n)
//     {
//         this->n = n;
//         visited.resize(n, false);
//         comp.clear();
//         adj.resize(n);
//         radj.resize(n);
//         order.clear();
//     }

//     void addEdge(int u, int v)
//     {
//         adj[u].push_back(v);
//         radj[v].push_back(u);
//     }

//     void dfs1(int u)
//     {
//         visited[u] = true;
//         for (auto v : adj[u])
//         {
//             if (!visited[v])
//             {
//                 dfs1(v);
//             }
//         }
//         order.push_back(u);
//     }

//     void dfs2(int u)
//     {
//         visited[u] = true;
//         comp.push_back(u);
//         for (auto v : radj[u])
//         {
//             if (!visited[v])
//             {
//                 dfs2(v);
//             }
//         }
//     }

//     void run()
//     {
//         for (int i = 0; i < n; i++)
//         {
//             if (!visited[i])
//             {
//                 dfs1(i);
//             }
//         }
//         reverse(order.begin(), order.end());
//         fill(visited.begin(), visited.end(), false);
//         for (auto i : order)
//         {
//             if (!visited[i])
//             {
//                 comp.clear();
//                 dfs2(i);
//                 scc.push_back(comp);
//             }
//         }
//     }
// };

struct kosaraju
{
    int n, scc_count = 0;
    vector<vector<int>> adj, radj, scc;
    vector<int> vis, order, comp_id;

    kosaraju(int n)
    {
        this->n = n;
        adj.resize(n);
        radj.resize(n);
        vis.assign(n, 0);
        comp_id.assign(n, -1);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    void dfs1(int u)
    {
        vis[u] = 1;
        for (int v : adj[u])
            if (!vis[v])
                dfs1(v);
        order.push_back(u);
    }

    void dfs2(int u)
    {
        vis[u] = 1;
        comp_id[u] = scc_count;
        scc.back().push_back(u);

        for (int v : radj[u])
            if (!vis[v])
                dfs2(v);
    }

    void run()
    {
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs1(i);

        reverse(order.begin(), order.end());

        fill(vis.begin(), vis.end(), 0);

        for (int u : order)
        {
            if (!vis[u])
            {
                scc.push_back({});
                dfs2(u);
                scc_count++;
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    kosaraju kr(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        kr.addEdge(u, v);
    }
    kr.run();

    auto &scc = kr.scc;
    for (auto comp : scc)
    {
        cout << "{ ";
        for (auto el : comp)
        {
            cout << el + 1 << " ";
        }
        cout << "}" << endl;
    }
}
