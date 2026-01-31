#include <bits/stdc++.h>
using namespace std;

int count_subset_sum(int i, int sum, int k, vector<int> &arr)
{
    if (i == arr.size())
    {
        return sum == k ? 1 : 0;
    }

    int take = count_subset_sum(i + 1, sum + arr[i], k, arr);
    int not_take = count_subset_sum(i + 1, sum, k, arr);

    return take + not_take;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    cout << count_subset_sum(0, sum, k, arr) << endl;
}