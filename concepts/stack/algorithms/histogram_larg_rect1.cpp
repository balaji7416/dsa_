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

    int max_area = 0;
    int width, height;
    for (int i = 0; i < n; i++)
    {
        height = INT_MAX;
        for (int j = i; j < n; j++)
        {
            width = j - i + 1;
            height = min(height, arr[j]);
            max_area = max(max_area, width * height);
        }
    }

    cout << max_area << endl;

    return 0;
}