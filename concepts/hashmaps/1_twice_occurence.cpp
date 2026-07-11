#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr)
{
    unordered_map<int, int> mp;
    for (auto el : arr)
    {
        if (mp[el] == 1)
        {
            return true;
        }
        mp[el]++;
    }
    return false;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (check(arr))
    {
        cout << "a element occurred 2 or more times" << endl;
    }
    else
    {
        cout << "no repetition of any element" << endl;
    }
}