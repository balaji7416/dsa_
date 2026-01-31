#include <bits/stdc++.h>
using namespace std;

void generate(vector<int> &curr, vector<int> &arr, vector<vector<int>> &ans, int i)
{
    if (i == arr.size())
    {
        // base case
        ans.push_back(curr);
        return;
    }

    // include curr element and recurse
    curr.push_back(arr[i]);
    generate(curr, arr, ans, i + 1);

    // back track and recurse
    curr.pop_back();
    generate(curr, arr, ans, i + 1);
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
    generate(curr, arr, ans, 0);

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