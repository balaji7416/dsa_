#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 50, -50, 1};

    int currentSum = 0, maxSum = INT_MIN;
    int start = 0, end = 0, tempStart = 0;

    for (int i = 0; i < arr.size(); i++)
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

    cout << "max subarray sum is: " << maxSum << endl;
    cout << "in the range " << start << " to " << end << endl;
}