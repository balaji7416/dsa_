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
    int max_area = 0;
    arr.push_back(0);
    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && arr[i] < arr[s.top()])
        {
            int height = arr[s.top()];
            s.pop();
            int width = i - (s.empty() ? -1 : s.top()) - 1;
            max_area = max(max_area, height * width);
        }
        s.push(i);
    }
    cout << max_area << endl;
    return 0;
}