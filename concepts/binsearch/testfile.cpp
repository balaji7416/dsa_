#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, vector<int>> mp;
    mp[1] = {1, 2};
    auto &vec = mp[1];
    vec.push_back(3);

    int *n = new int(10);
    int *m = n;
    *m = 39;

    cout << *n << endl;
    // for (auto i : mp[1])
    // {
    //     cout << i << " ";
    // }
}