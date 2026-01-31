#include <bits/stdc++.h>
using namespace std;

void combine(int idx, int k, vector<int> &curr, vector<int> &arr, vector<vector<int>> &ans)
{
    if (curr.size() == k)
    {
        ans.push_back(curr);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (i > idx && arr[i] == arr[i - 1])
            continue;
        curr.push_back(arr[i]);
        combine(i + 1, k, curr, arr, ans);
        curr.pop_back();
    }
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
    vector<int> curr;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    combine(0, k, curr, arr, ans);

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