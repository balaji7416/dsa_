#include <bits/stdc++.h>
using namespace std;

/*
    dp[i][w] = the max value i can obtain from my current idx to n-1 with my current weight
               following the constraint
*/

/*
In C++,
TLE and AC are often just an '&' apart.
*/

class Solution
{
public:
    int solve(int idx, int cw, int W, vector<int> &val, vector<int> wt, vector<vector<int>> &dp)
    {
        if (idx == val.size())
        {
            return 0;
        }

        if (dp[idx][cw] != -1)
            return dp[idx][cw];

        int not_take = solve(idx + 1, cw, W, val, wt, dp);

        int take = 0;
        if (cw + wt[idx] <= W)
        {
            take = val[idx] + solve(idx + 1, cw + wt[idx], W, val, wt, dp);
        }

        return dp[idx][cw] = max(take, not_take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        // code here
        int n = val.size();
        int cw = 0; // current weight
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(0, cw, W, val, wt, dp);
    }
};