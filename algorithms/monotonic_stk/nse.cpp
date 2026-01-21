#include <bits/stdc++.h>
using namespace std;

int main()
{
    // code for next smaller element to the right
    vector<int> arr = {5, 7, 4, 2, 5, 3, 1};

    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() and arr[i] < arr[stk.top()])
        {
            ans[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}