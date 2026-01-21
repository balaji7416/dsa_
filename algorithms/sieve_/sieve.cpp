#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    long long n;
    cin >> n;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (long long j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    isPrime[n] ? cout << "Prime" << endl : cout << "not prime" << endl;
    // is_prime(n) ? cout << "Prime" << endl : cout << "not prime" << endl;
}
