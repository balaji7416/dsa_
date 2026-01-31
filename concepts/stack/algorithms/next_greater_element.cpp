#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<int> s;
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        if (!s.empty())
            ans[i] = s.top();
        s.push(arr[i]);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}