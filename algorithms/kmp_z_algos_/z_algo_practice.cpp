#include <bits/stdc++.h>
using namespace std;

vector<int> build_z(string s)
{
    int l = 0, r = 0;
    int n = s.size();
    vector<int> z(n, 0);
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
                z[i] = r - l + 1;
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

    bool found = false;
    int idx = 0;
    for (int i = p.size() + 1; i < new_str.size(); i++)
    {
        if (z[i] == p.size())
        {
            found = true;
            idx = i - p.size() - 1;
        }
    }

    if (found)
    {
        cout << "pattern found at index: " << idx << endl;
    }
    else
    {
        cout << "pattern not found" << endl;
    }
}