#include <bits/stdc++.h>
using namespace std;

void permute(int idx, vector<int> &arr, vector<vector<int>> &ans)
{
    if (idx == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (i > idx && arr[i] == arr[idx])
            continue;

        swap(arr[idx], arr[i]);
        permute(idx + 1, arr, ans);
        swap(arr[idx], arr[i]);
    }
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
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    permute(0, arr, ans);
    for (auto v : ans)
    {
        cout << "[ ";
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
}