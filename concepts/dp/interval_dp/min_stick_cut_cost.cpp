#include <bits/stdc++.h>
using namespace std;

/*
    f(l,r) => minm cost of cutting stick of betweeen pos l and r at positions defined in cuts
    base case:
        if(l >= r):
            return 0        // no cut possible for stick of len = 0
    #note:
        the condition if(cuts[i] <= l || cuts[i] >= r) is very important
        it should skip cuts equal to l and r since they are already cut

    #time: O(n^2)
*/

int min_cost(int l, int r, vector<int> &cuts, vector<vector<int>> &dp)
{
    // if stick is empty
    if (l >= r)
        return 0;

    // if memorized
    if (dp[l][r] != -1)
        return dp[l][r];

    int minCost = INT_MAX;
    for (int i = 0; i < cuts.size(); i++)
    {
        // if cut idx is out of range (very important)
        if (cuts[i] <= l || cuts[i] >= r)
            continue;

        int cost = r - l + min_cost(l, cuts[i], cuts, dp) // cost of cutting stick in left part
                   + min_cost(cuts[i], r, cuts, dp);      // cost cutting stick in right part
        minCost = min(minCost, cost);
    }
    return dp[l][r] = (minCost == INT_MAX ? 0 : minCost); // if no cut is possible return 0
}

int main()
{

    // n -> len of stick, k -> no.of cuts
    int n, k;
    cin >> n >> k;

    vector<int> arr(k);
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = min_cost(0, n, arr, dp);
    cout << ans << endl;
    return 0;
}