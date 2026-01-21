#include <bits/stdc++.h>
using namespace std;

vector<int> build_z(string s)
{
    int n = s.size();
    vector<int> z(n, 0);
    int r = 0, l = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (i < n and s[r] == s[r - l])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            int remaining = r - i + 1;
            if (z[k] < remaining)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (r + 1 < n and s[r + 1] == s[r + 1 - l])
                    r++;
                z[i] = r + 1 - l;
                r--;
            }
        }
    }
    return z;
}

int main()
{
    string t, p;
    cin >> t >> p;
    string new_str = p + "#" + t;
    vector<int> z = build_z(new_str);

    vector<int> result;
    for (int i = 0; i < z.size(); i++)
    {
        if (z[i] == p.size())
        {
            result.push_back(i - p.size() - 1);
        }
    }

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
    return 0;
}