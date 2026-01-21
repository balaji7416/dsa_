#include <bits/stdc++.h>
using namespace std;

vector<int> rabin_karp(string &t, string &p)
{
    long long n = t.size(), m = p.size();

    long long base = 31;
    long long mod = 1e9 + 9;

    long long patternHash = 0;
    long long textHash = 0;
    vector<int> result;

    long long power = 1;
    for (long long i = 0; i < m - 1; i++)
    {
        power *= base;
        power %= mod;
    }

    for (long long i = 0; i < m; i++)
    {
        textHash = (textHash * base + t[i]) % mod;
        patternHash = (patternHash * base + p[i]) % mod;
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

        // compute the hash for next iteration
        if (i < n - m)
        {
            textHash = (textHash - (t[i] * power) % mod + mod) % mod;
            textHash = ((textHash * base) % mod + t[i + m]) % mod;
        }
    }
    return result;
}

int main()
{
    string t, p;
    cin >> t >> p;

    vector<int> occurrences = rabin_karp(t, p);

    if (occurrences.empty())
    {
        cout << "pattern not found" << endl;
    }
    else
    {
        cout << "pattern found at indices: " << endl;
        for (auto i : occurrences)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}