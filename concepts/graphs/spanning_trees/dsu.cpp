#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, size;
    int components;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // find
    int find(int n)
    {
        if (parent[n] == n)
            return n;
        return parent[n] = find(parent[n]);
    }

    // unite
    bool unite(int x, int y)
    {
        int rootA = find(x);
        int rootB = find(y);

        if (rootA == rootB)
            return false;

        if (size[rootA] < size[rootB])
            swap(rootA, rootB);

        parent[rootB] = rootA;
        size[rootA] += size[rootB];
        components--;
        return true;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        if (!dsu.unite(u, v))
        {
            cout << "Cycle Found" << endl;
            return 0;
        }
        else
        {
            cout << "edge added" << endl;
        }

        adj[u].push_back(v);
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
int32_t main()
{
    ios::sync_with_stdio(false);

    return 0;
}