#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int up = *upper_bound(arr.begin(), arr.end(), x);
    cout << up << endl;
    // frequency of x in arr
    // cout << upper_bound(arr.begin(), arr.end(), x) - lower_bound(arr.begin(), arr.end(), x);
    return 0;
}