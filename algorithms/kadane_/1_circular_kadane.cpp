#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {-1, -4, -1, -5};
    int n = arr.size();
    int currentSum = 0, maxSum = INT_MIN;
    int tempStart = 0, start = 0, end = 0;

    // finding normal max subarray sum
    for (int i = 0; i < n; i++)
    {
        if (currentSum + arr[i] < arr[i])
        {
            currentSum = arr[i];
            tempStart = i;
        }
        else
        {
            currentSum += arr[i];
        }

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    int tempStart1 = 0, start1 = 0, end1 = 0;
    int currentSum1 = 0, minSum1 = INT_MAX;
    // finding normal min subarray sum
    for (int i = 0; i < n; i++)
    {
        if (currentSum1 + arr[i] > arr[i])
        {
            currentSum1 = arr[i];
            tempStart1 = i;
        }
        else
        {
            currentSum1 += arr[i];
        }

        if (currentSum1 < minSum1)
        {
            minSum1 = currentSum1;
            start1 = tempStart1;
            end1 = i;
        }
    }

    // max wrap sum
    int maxWrampSum = accumulate(arr.begin(), arr.end(), 0) - minSum1;

    if (maxWrampSum == 0)
    {
        cout << "maxSum: " << maxSum << endl;
        for (int i = start; i <= end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        if (maxWrampSum > maxSum)
        {
            cout << "maxSum: " << maxWrampSum << endl;
            for (int i = 0; i < n; i++)
            {
                if (i >= start1 and i <= end1)
                {
                    continue;
                }
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "maxSum: " << maxSum << endl;
            for (int i = start; i <= end; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}