#include <bits/stdc++.h>
using namespace std;

struct info
{
    int currSum;
    int bestSum;
    info() {}
    info(int curr, int best) : currSum(curr), bestSum(best) {}
};

info kadane(vector<int> &arr, int i)
{
    int n = arr.size();
    if (i == n - 1)
    {
        return info(arr[i], arr[i]);
    }
    info rest = kadane(arr, i + 1);
    int currSum = max(arr[i], rest.currSum + arr[i]);
    int bestSum = max(rest.bestSum, currSum);
    return info(currSum, bestSum);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max_subarr_sum = kadane(arr, 0).bestSum;
    cout << max_subarr_sum << endl;
}