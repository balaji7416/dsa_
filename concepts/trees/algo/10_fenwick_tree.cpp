#include <bits/stdc++.h>
using namespace std;

struct fenwick
{
    int n;
    vector<int> bit;

    fenwick(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int i, int val)
    {
        i = i + 1;
        while (i <= n)
        {
            bit[i] += val;
            i += (i & -i);
        }
    }

    /*sum(i) returns sum of first 0,...,i elements of arr
     */
    int sum(int i)
    {
        i = i + 1;
        int s = 0;
        while (i > 0)
        {
            s += bit[i];
            i -= (i & -i);
        }
        return s;
    }

    int range(int l, int r)
    {
        if (l > r)
            return 0;
        return sum(r) - (l ? sum(l - 1) : 0);
    }
};

int main()
{
    vector<int> arr = {2, 4, 6, 8};
    int n = arr.size();
    fenwick fw(n);
    for (int i = 0; i < n; i++)
    {
        fw.add(i, arr[i]);
    }

    cout << fw.range(0, 2) << endl;
    return 0;
}
