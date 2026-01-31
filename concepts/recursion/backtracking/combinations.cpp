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
        curr.push_back(arr[i]);
        combine(i + 1, k, curr, arr, ans);

        curr.pop_back();
    }
}

int main()
{
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> curr;
    vector<vector<int>> ans;
    combine(0, r, curr, arr, ans);
    for (auto v : ans)
    {
        cout << "[ ";
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}