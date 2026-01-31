#include <bits/stdc++.h>
using namespace std;
#define int long long
int fib(int n, unordered_map<int, int> &dp)
{
    if (n <= 1)
        return n;
    if (dp.count(n))
        return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int32_t main()
{
    int n;
    cin >> n;
    unordered_map<int, int> dp;
    cout << fib(n, dp) << endl;

    return 0;
}