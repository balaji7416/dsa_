#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int LOG = 20;

vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;

void dfs(int u, int p)
{
    up[u][0] = p;

    for (int i = 1; i < LOG; i++)
    {
        if (up[u][i - 1] == -1)
            continue;
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        depth[v] = 1 + depth[u];
        dfs(v, u);
    }
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n);
    up.resize(n, vector<int>(LOG, -1));
    depth.resize(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        // u--;
        // v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    // for (auto vec : up)
    // {
    //     for (auto i : vec)
    //         cout << i << " ";
    //     cout << endl;
    // }
    // return 0;
    auto jump = [&](int u, int k)
    {
        for (int i = 0; i < LOG; i++)
        {
            if (k & (1 << i))
            {
                u = up[u][i];
                if (u == -1)
                    return -1;
            }
        }
        return u;
    };

    int q;
    cin >> q;
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        x--;
        int ans = jump(x, k);
        ans == -1 ? cout << ans << endl : cout << ans + 1 << endl;
    }
    return 0;
}