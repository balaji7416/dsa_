#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, -2, 3, -1};
    int currentSum = 0, maxSum = INT_MIN;
    int n = arr.size();
    int start = 0, end = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > maxSum)
            {
                maxSum = sum;
                start = i;
                end = j;
            }
        }
    }
    cout << "maxSum: " << maxSum << endl;
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}