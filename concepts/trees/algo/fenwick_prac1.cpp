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
        i++;
        while (i <= n)
        {
            bit[i] += val;
            i += i & -i;
        }
    }

    int sum(int i)
    {
        i++;
        int s = 0;
        while (i > 0)
        {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    int range_sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;

    fenwick fw(n);
    for (int i = 0; i < n; i++)
    {
        fw.add(i, nums[i]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l;
        int r;
        cin >> l >> r;
        cout << fw.range_sum(l, r) << endl;
    }
    return 0;
}