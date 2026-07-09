#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = n, l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) >> 1;
        if (arr[mid] >= k)
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;

    // stl function
    cout << lower_bound(arr.begin(), arr.end(), k) - arr.begin() << endl;
    return 0;
}