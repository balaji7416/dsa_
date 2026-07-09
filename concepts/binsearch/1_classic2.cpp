#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int target;
    cin >> target;
    int l = 0, h = n - 1;
    int ans = -1;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (arr[m] == target)
        {
            ans = m;
            break;
        }
        else if (arr[m] > target)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    if (ans == -1)
        cout << target << " not found" << endl;
    else
        cout << "target found at " << ans << endl;
    return 0;
}