#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, -2, 3, 4, 5};
    int n = arr.size();
    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    int maxSum = INT_MIN;
    int minPrefix = 0;
    int start = 0, end = 0;
    for (int i = 1; i <= n; i++)
    {
        if (prefix[i] - minPrefix > maxSum)
        {
            maxSum = prefix[i] - minPrefix;
            end = i - 1;
        }
        if (prefix[i] < minPrefix)
        {
            minPrefix = prefix[i];
            start = i;
        }
    }

    cout << "maxSum : " << maxSum << endl;
    cout << "in the range " << start << " to " << end << endl;
}