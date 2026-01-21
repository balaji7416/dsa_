#include <bits/stdc++.h>
using namespace std;

const int p = 31;
const int mod = 1e9 + 9;

long long getHash(int l, int r, vector<long long> &prefix, vector<long long> &power, int n)
{
    long long raw_hash = prefix[r + 1] - prefix[l];
    if (raw_hash < 0)
        raw_hash += mod;
    long long normalised_hash = (raw_hash * power[n - (r + 1)]) % mod;
    return normalised_hash;
}

int main()
{
    string s = "abcdcd";
    int n = s.size();

    vector<long long> power(n + 1), prefix_hash(n + 1);

    // fill the power series
    power[0] = 1;
    for (int i = 1; i < n; i++)
    {
        power[i] = (1LL * power[i - 1] * p) % mod;
    }

    // fill the prefix hashes
    prefix_hash[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix_hash[i] = (prefix_hash[i - 1] + (s[i - 1] - 'a' + 1) * power[i - 1] % mod) % mod;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int l1, r1;
        cin >> l1 >> r1;
        int l2, r2;
        cin >> l2 >> r2;

        if (getHash(l1, r1, prefix_hash, power, n) == getHash(l2, r2, prefix_hash, power, n))
        {
            cout << "both are same" << endl;
        }
        else
        {
            cout << "both are different" << endl;
        }
    }
}