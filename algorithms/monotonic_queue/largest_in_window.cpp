#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    deque<int> dq;
    vector<int> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() and dq.front() == i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() and arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
        {
            ans.push_back(arr[dq.front()]);
        }
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
