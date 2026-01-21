#include <bits/stdc++.h>
using namespace std;

vector<int> build_z(string s)
{
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n and s[r] == s[r - l])
            {
                r++;
            }
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
                {
                    r++;
                }
                z[i] = r + 1 - l;
            }
        }
    }
    return z;
}

int main()
{
    string s, p;
    cin >> s >> p;
    string new_str = p + "#" + s;
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
}