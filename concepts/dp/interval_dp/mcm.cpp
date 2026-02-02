#include <bits/stdc++.h>
using namespace std;

/*

    f(i,j) => min cost to multiply matrices from i to j
    base cases:
        if(i >= j) return 0;    since there's no cost to multiply a single matix

        f(i,j) = min(f(i,k) + f(k+1,j) + arr[i]*arr[k+1]*arr[j+1]) for all k belongs to [i,j); i.e., for all splits

    here i is started from 0,
    i.e., for 3 matrices the function will be f(0,2) and
    for matrix i :
    no.of rows = arr[i],
    no.of cols = arr[i+1]
*/

int min_cost(int i, int j, vector<int> &arr, vector<vector<int>> &dp, vector<vector<int>> &split)
{
    // if single matrix
    if (i >= j)
        return 0;

    // if memorized
    if (dp[i][j] != -1)
        return dp[i][j];

    int minCost = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = min_cost(i, k, arr, dp, split)       // resulting matrix dimensions arr[i]*arr[k+1]
                   + min_cost(k + 1, j, arr, dp, split) // resulting matrix dimensions arr[k+1]*arr[j+1]
                   + arr[i] * arr[k + 1] * arr[j + 1];  // cost for multiplying the 2 resulting matrices
        if (cost < minCost)
        {
            minCost = cost;
            split[i][j] = k;
        }
    }
    return dp[i][j] = minCost;
}

void build_paranthesis(int i, int j, vector<vector<int>> &split)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    build_paranthesis(i, split[i][j], split);
    build_paranthesis(split[i][j] + 1, j, split);
    cout << ")";
}

int main()
{
    int n; // n means no.of matrices + 1 since we are taking dimension inputs
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> split(n, vector<int>(n, -1));
    int ans = min_cost(0, n - 2, arr, dp, split);
    cout << ans << endl;
    build_paranthesis(0, n - 2, split);
    return 0;
}