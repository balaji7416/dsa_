#include <bits/stdc++.h>
using namespace std;

void subsetSum(int i, int k, int &currSum, vector<int> &ans, vector<int> &arr)
{
    if (i == arr.size())
    {
        // base case
        if (currSum == k)
        {
            cout << "[ ";
            for (auto j : ans)
            {
                cout << j << " ";
            }
            cout << "]" << endl;
        }
        return;
    }

    // choose + recurse
    ans.push_back(arr[i]);
    currSum += arr[i];
    subsetSum(i + 1, k, currSum, ans, arr);

    // undo + recurse
    ans.pop_back();
    currSum -= arr[i];
    subsetSum(i + 1, k, currSum, ans, arr);
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
    int currSum = 0;
    vector<int> ans;
    subsetSum(0, k, currSum, ans, arr);

    return 0;
}