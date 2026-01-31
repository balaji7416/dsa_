#include <bits/stdc++.h>
using namespace std;

vector<int> removeAll(vector<int> &arr, int k, int i)
{
    int n = arr.size();
    if (i == n)
    {
        return {};
    }
    vector<int> res = removeAll(arr, k, i + 1);
    if (arr[i] != k)
    {
        res.insert(res.begin(), arr[i]);
    }
    return res;
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
    vector<int> modified_arr = removeAll(arr, k, 0);
    for (auto i : modified_arr)
    {
        cout << i << " ";
    }
    cout << endl;
}