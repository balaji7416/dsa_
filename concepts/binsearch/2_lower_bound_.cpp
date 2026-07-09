#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    float k;
    cin >> k;

    /*
        lower bound of k: first element >= k
    */

    int l = 0, h = n - 1, ans = -1;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (nums[m] >= k)
        {
            ans = nums[m];
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    ans == -1 ? cout << "not element found" << endl : cout << ans << endl;

    return 0;
}