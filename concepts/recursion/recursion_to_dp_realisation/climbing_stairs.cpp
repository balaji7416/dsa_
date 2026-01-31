#include <bits/stdc++.h>
using namespace std;
#define int long long
int ways_to_climb(int n, unordered_map<int, int> &dp)
{
    if (n <= 1)
        return 1;

    if (dp.count(n))
        return dp[n];
    return dp[n] = ways_to_climb(n - 1, dp) + ways_to_climb(n - 2, dp);
}

int32_t main()
{
    int n;
    cin >> n;
    unordered_map<int, int> dp;
    cout << ways_to_climb(n, dp) << endl;
    return 0;
}