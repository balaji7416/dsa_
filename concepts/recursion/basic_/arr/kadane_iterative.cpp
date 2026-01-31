#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int curr_sum = 0, max_sum = INT_MIN;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum = max(arr[i], curr_sum + arr[i]);
        if (curr_sum > max_sum)
        {
            max_sum = curr_sum;
            r = i;
        }
    }
    for (int i = l; i <= r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << max_sum << endl;
}