#include <bits/stdc++.h>
using namespace std;

// struct tarjan
// {
//     int n, timer, scc_count;
//     vector<int> tin, low;
//     vector<vector<int>> adj, scc;
//     vector<bool> inStack;
//     stack<int> stk;
//     vector<int> comp_id;

//     tarjan(int n)
//     {
//         scc_count = 0;
//         comp_id.resize(n);
//         timer = 0;
//         this->n = n;
//         tin.resize(n, -1);
//         low.resize(n);
//         adj.resize(n);
//         inStack.resize(n, false);
//     }

//     void addEdge(int u, int v)
//     {
//         adj[u].push_back(v);
//     }

//     void dfs(int u)
//     {
//         tin[u] = low[u] = timer++;
//         inStack[u] = true;
//         stk.push(u);
//         for (auto v : adj[u])
//         {
//             if (tin[v] == -1)
//             {
//                 dfs(v);
//                 low[u] = min(low[u], low[v]);
//             }
//             else if (inStack[v])
//             {
//                 low[u] = min(low[u], tin[v]);
//             }
//         }

//         if (low[u] == tin[u])
//         {
//             vector<int> comp;
//             while (true)
//             {
//                 int v = stk.top();
//                 stk.pop();
//                 inStack[v] = false;
//                 comp.push_back(v);
//                 comp_id[v] = scc_count;
//                 if (u == v)
//                     break;
//             }
//             scc.push_back(comp);
//             scc_count++;
//         }
//     }

//     void run()
//     {
//         for (int i = 0; i < n; i++)
//         {
//             if (tin[i] == -1)
//             {
//                 dfs(i);
//             }
//         }
//     }
// };

struct Tarjan
{
    int n, timer = 0, scc_count = 0;
    vector<vector<int>> adj, scc;
    vector<int> tin, low, comp_id;
    vector<bool> inStack;
    stack<int> st;

    Tarjan(int n) : n(n)
    {
        adj.resize(n);
        tin.assign(n, -1);
        low.resize(n);
        comp_id.assign(n, -1);
        inStack.assign(n, false);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void dfs(int u)
    {
        tin[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u])
        {
            if (tin[v] == -1)
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if (inStack[v])
            {
                low[u] = min(low[u], tin[v]);
            }
        }

        if (tin[u] == low[u])
        {
            vector<int> comp;
            while (true)
            {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                comp.push_back(v);
                comp_id[v] = scc_count;
                if (v == u)
                    break;
            }
            scc.push_back(comp);
            scc_count++;
        }
    }

    void run()
    {
        for (int i = 0; i < n; i++)
            if (tin[i] == -1)
                dfs(i);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Tarjan tarj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tarj.addEdge(u, v);
    }

    tarj.run();

    auto &scc = tarj.scc;
    for (auto &comp : scc)
    {
        cout << "{ ";
        for (auto el : comp)
        {
            cout << el + 1 << " ";
        }
        cout << "}" << endl;
    }
    auto &comp_id = tarj.comp_id;
    for (auto el : comp_id)
    {
        cout << el + 1 << " ";
    }
}