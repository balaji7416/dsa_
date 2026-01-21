#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, -2, 3, -1};
    int currentSum = 0, maxSum = INT_MIN;
    int n = arr.size();
    int tempStart = 0, start = 0, end = 0;
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

    cout << "maxSum: " << maxSum << endl;
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}