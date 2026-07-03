#include <bits/stdc++.h>
using namespace std;
struct bellman_ford
{
    int n;
    vector<tuple<int, int, int>> edges;
    vector<vector<int>> adj;
    vector<int> dist;
    const int inf = INT_MAX;
    bool neg_cyle;
    vector<bool> bad;
    bellman_ford(int n)
    {
        this->n = n;
        neg_cyle = false;
        dist.resize(n, inf);
        adj.resize(n);
        bad.resize(n, false);
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({u, v, w});
        adj[u].push_back(v);
    }

    void run(int src)
    {
        dist[src] = 0;
        bool changed = false;
        for (int i = 0; i < n - 1; i++)
        {
            changed = false;
            for (auto &[u, v, w] : edges)
            {
                if (dist[u] != inf && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }
            if (!changed)
                break;
        }
        // detect negative cycle
        for (auto &[u, v, w] : edges)
        {
            if (dist[u] != inf && dist[u] + w < dist[v])
            {
                neg_cyle = true;
                bad[v] = true;
            }
        }

        if (!neg_cyle)
            return;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (bad[i])
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (!bad[v])
                {
                    bad[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    bellman_ford bf(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // u--;
        // v--;
        bf.addEdge(u, v, w);
    }

    bf.run(0);

    if (bf.neg_cyle)
    {
        cout << "Neg cycle found " << endl;
        for (int i = 0; i < n; i++)
        {
            if (bf.bad[i])
            {
                cout << "B" << " ";
            }
            else
            {
                cout << "G" << " ";
            }
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < bf.dist.size(); i++)
        {
            cout << bf.dist[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

struct BellmanFord
{
    struct Edge
    {
        int u, v;
        long long w;
    };

    int n;
    const long long INF = 1e18;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<long long> dist;
    vector<bool> bad;
    bool neg_cycle = false;

    BellmanFord(int n) : n(n)
    {
        dist.assign(n, INF);
        adj.resize(n);
        bad.assign(n, false);
    }

    void addEdge(int u, int v, long long w)
    {
        edges.push_back({u, v, w});
        adj[u].push_back(v);
    }

    void run(int src)
    {
        dist[src] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            bool changed = false;

            for (auto &e : edges)
            {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
                {
                    dist[e.v] = dist[e.u] + e.w;
                    changed = true;
                }
            }

            if (!changed)
                break;
        }

        for (auto &e : edges)
        {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
            {
                neg_cycle = true;
                bad[e.v] = true;
            }
        }

        if (!neg_cycle)
            return;

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (bad[i])
                q.push(i);
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (!bad[v])
                {
                    bad[v] = true;
                    q.push(v);
                }
            }
        }
    }
};