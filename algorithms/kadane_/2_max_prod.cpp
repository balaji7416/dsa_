#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, -2, 2, -1};
    int n = arr.size();
    int maxCurrProd = arr[0], minCurrProd = arr[0], maxProd = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        if (x < 0)
        {
            swap(maxCurrProd, minCurrProd);
        }

        maxCurrProd = max(x, maxCurrProd * x);
        minCurrProd = min(x, minCurrProd * x);

        maxProd = max(maxProd, maxCurrProd);
    }

    cout << "max subarray product: " << maxProd << endl;
}