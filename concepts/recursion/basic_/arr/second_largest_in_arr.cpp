#include <bits/stdc++.h>
using namespace std;

pair<int, int> second_largest(vector<int> &arr, int n, int i)
{
    if (i == n - 1)
    {
        return {arr[i], INT_MIN};
    }
    pair<int, int> res = second_largest(arr, n, i + 1);
    auto [max1, max2] = res;
    if (arr[i] > max1)
    {
        return {arr[i], max1};
    }
    else if (arr[i] > max2 && arr[i] != max1)
    {
        return {max1, arr[i]};
    }
    else
    {
        return res;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << second_largest(arr, n, 0).second << endl;
}