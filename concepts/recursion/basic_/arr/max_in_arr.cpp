#include <bits/stdc++.h>
using namespace std;

int maxm(vector<int> arr, int n, int i)
{
    if (i == n - 1)
        return arr[i];
    int max_in_rest = maxm(arr, n, i + 1);
    return max(arr[i], max_in_rest);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxm(arr, n, 0) << endl;
}