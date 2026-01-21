#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefix(arr.size() + 1, 0);

    for (int i = 1; i <= arr.size(); i++)
        prefix[i] = prefix[i - 1] + arr[i - 1];

    int maxSum = INT_MIN;
    int minPrefix = 0;
    int minIdx = 0;
    int maxIdx = 0;

    for (int i = 1; i <= arr.size(); i++)
    {
        if (prefix[i] - minPrefix > maxSum)
        {
            maxSum = prefix[i] - minPrefix;
            maxIdx = i - 1;
        }

        if (prefix[i] < minPrefix)
        {
            minPrefix = prefix[i];
            minIdx = i; // store prefix index
        }
    }

    cout << "max subarray sum: " << maxSum << endl;
    cout << "in the range: " << minIdx << " to " << maxIdx << endl;
}
