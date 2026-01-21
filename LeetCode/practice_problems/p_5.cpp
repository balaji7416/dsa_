#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        bool palindrome = true;
        for (int i = 0; i <= n / 2 - 1; i++)
        {
            if (s[i] != s[n - i - 1])
            {
                palindrome = false;
                break;
            }
        }
        return palindrome;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            string subStr = "";
            for (int j = i; j < n; j++)
            {
                subStr += s[j];
                if (isPalindrome(subStr))
                {
                    ans = subStr.size() > ans.size() ? subStr : ans;
                }
            }
        }
        return ans;
    }
};