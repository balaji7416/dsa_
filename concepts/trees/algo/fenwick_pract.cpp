#include <bits/stdc++.h>
using namespace std;

struct fenwick
{
    int n;
    vector<int> bit;
    fenwick(int n)
    {
        this->n = n;
        bit.resize(n + 1, 0);
    }

    void add(int i, int val)
    {
        i++;
        while (i <= n)
        {
            bit[i] += val;
            i += (i & -i);
        }
    }

    int sum(int i)
    {
        i++;
        int s = 0;
        while (i > 0)
        {
            s += bit[i];
            i -= (i & -i);
        }
        return s;
    }

    int range(int l, int r)
    {
        if (l > r)
            return 0;
        return sum(r) - (l ? sum(l - 1) : 0);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    vector<int> tin(n, 0), sz(n, 0), flat(n, 0);
    int timer = 0;
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        tin[u] = timer;
        flat[timer] = u;
        timer++;
        sz[u] = 1;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
    };

    // call dfs
    dfs(dfs, 0, -1);

    // now fenwick
    fenwick fw(n);
    for (int i = 0; i < n; i++)
    {
        fw.add(tin[i], val[i]);

        // or better do
        // fw.add(i, val[flat[i]]);
    }
    /*
     to query the subtree of node i , use range
     [tin[i], tin[i]+sz[i]-1]
    */
    return 0;
}
