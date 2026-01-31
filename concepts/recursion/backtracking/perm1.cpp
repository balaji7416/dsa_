#include <bits/stdc++.h>
using namespace std;

void permute(vector<int> &curr, vector<int> &arr, vector<vector<int>> &ans, unordered_set<int> &visited)
{
    if (curr.size() == arr.size())
    {
        ans.push_back(curr);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (visited.count(arr[i]))
            continue;

        visited.insert(arr[i]);
        curr.push_back(arr[i]);
        permute(curr, arr, ans, visited);

        curr.pop_back();
        visited.erase(arr[i]);
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

    unordered_set<int> visited;
    vector<vector<int>> ans;
    vector<int> curr;

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
}