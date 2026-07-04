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

    int q;
    cin >> q;

    int mx = *max_element(nums.begin(), nums.end());
    fenwick fw(mx + 1);

    // frequency fenwcik, for answering no.of elements < a number
    for (int x : nums)
    {
        fw.add(x, 1);
    }

    while (q--)
    {
        int l;
        cin >> l;
        cout << fw.sum(l - 1) << endl;
    }
}