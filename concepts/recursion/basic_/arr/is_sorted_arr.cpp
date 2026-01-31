#include <bits/stdc++.h>
using namespace std;

bool is_sorted(vector<int> arr, int n, int i)
{
    if (i == n - 1)
        return true;
    if (arr[i] > arr[i + 1])
        return false;
    return is_sorted(arr, n, i + 1);
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
    is_sorted(arr, n, 0) ? cout << "Sorted" << endl : cout << "Not sorted" << endl;
}