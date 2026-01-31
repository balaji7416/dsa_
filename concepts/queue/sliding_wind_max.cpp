#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        /*
            First, we remove elements that are out of the window
            so everything left in the deque is guaranteed to belong to the current window.
            Then, if the newly inserted element is greater than some elements already in the deque,
            those elements can never be the max again
            because this new element exists in the current window
            and will also exist in all future windows where they would exist.
        */
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
        {
            ans.push_back(arr[dq.front()]);
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}