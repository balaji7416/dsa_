#include <bits/stdc++.h>
using namespace std;

void permute(vector<int> &curr, vector<int> &arr, vector<vector<int>> &ans, vector<bool> &visited)
{
    if (curr.size() == arr.size())
    {
        ans.push_back(curr);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (visited[i])
            continue;

        if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1])
            continue;

        visited[i] = true;
        curr.push_back(arr[i]);
        permute(curr, arr, ans, visited);

        curr.pop_back();
        visited[i] = false;
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
    vector<vector<int>> ans;
    vector<int> curr;
    // unordered_set<int> visited;
    vector<bool> visited(n, false);
    sort(arr.begin(), arr.end());
    permute(curr, arr, ans, visited);

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