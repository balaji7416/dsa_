#include <bits/stdc++.h>
using namespace std;

vector<long long> rabin_karp(string &t, string &p)
{
    long long n = t.size(), m = p.size();
    long long mod = 1e9 + 9;
    long long base = 31;
    long long power = 1;
    long long textHash = 0, patternHash = 0;
    vector<long long> result;
    for (long long i = 0; i < m - 1; i++)
    {
        power *= base;
        power %= mod;
    }

    for (long long i = 0; i < m; i++)
    {
        patternHash = (patternHash * base + p[i]) % mod;
        textHash = (textHash * base + t[i]) % mod;
    }

    for (long long i = 0; i <= n - m; i++)
    {
        if (textHash == patternHash)
        {
            bool match = true;
            for (long long j = 0; j < m; j++)
            {
                if (t[i + j] != p[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                result.push_back(i);
        }

        if (i < n - m)
        {
            textHash = (textHash - (t[i] * power) % mod + mod) % mod;
            textHash = (textHash * base % mod + t[i + m]) % mod;
        }
    }
    return result;
}

int main()
{
    string t, p;
    cin >> t >> p;
    vector<long long> result = rabin_karp(t, p);

    if (result.empty())
    {
        cout << "pattern not found" << endl;
    }
    else
    {
        cout << "pattern found at indices: " << endl;
        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}