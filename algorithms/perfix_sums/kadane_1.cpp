#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {-1, 2, -3, 4, -5, 7};
    int n = arr.size();
    int currentSum = 0, maxSum = INT_MIN, start = 0, end = 0, tempStart = 0;

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
    cout << "in the range " << start << " to " << end << endl;
}