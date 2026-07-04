#include <bits/stdc++.h>
using namespace std;

mt19937 rng(
    chrono::steady_clock::now().time_since_epoch().count());

int main()
{

    uniform_int_distribution<int> dist(1, 10);

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << dist(rng) << " ";
    // }

    vector<int> a = {1, 2, 3, 4, 5};
    shuffle(a.begin(), a.end(), rng);

    for (auto i : a)
        cout << i << " ";
    cout << endl;
}