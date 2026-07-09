#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int bin_search(int l, int r, int target)
{
    if (l > r)
        return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] < target)
        return bin_search(mid + 1, r, target);
    else
        return bin_search(l, mid - 1, target);
}

int main()
{
    int n, target;
    cin >> n >> target;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l = 0, h = n - 1;
    int ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    // cout << ans << endl;
    cout << bin_search(0, n - 1, target) << endl;
}