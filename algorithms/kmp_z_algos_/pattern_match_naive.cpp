#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcdefghi";
    int n = s.size();
    int t;
    cin >> t;
    while (t--)
    {
        string matching;
        cin >> matching;
        int m = matching.size();
        bool match = true;
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i, k = 0;
            pos = i;
            match = true;
            while (j < n and k < m)
            {
                if (s[j] == matching[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                break;
            }
        }
        if (match)
        {
            cout << "matching found in the string from pos: " << pos << endl;
        }
        else
        {
            cout << "matching not found " << endl;
        }
    }
}