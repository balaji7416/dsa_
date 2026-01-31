#include <bits/stdc++.h>
using namespace std;

int max_subarr_sum(vector<int> &arr, int i)
{
    int n = arr.size();
    if (i == n - 1)
        return arr[i];
    int max_subarr_sum_in_left = max_subarr_sum(arr, i + 1);
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
    int maxSubArrSum = max_subarr_sum(arr, 0);
    cout << maxSubArrSum << endl;
}