#include <bits/stdc++.h>
using namespace std;

int main()
{
    // code for next greater element to the right
    vector<int> arr = {2, 1, 3, 0, 2, 4, 3};

    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() and arr[i] > arr[stk.top()])
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