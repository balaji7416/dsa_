#include <bits/stdc++.h>
using namespace std;

/*
    f(i,j) => min cuts required to make in s[i:] to make every substring a palindrome
    base case:
        if string is empty no.of cuts needed = 0, but we return -1 as we need to cancel out the cut we included
        while recursing
        lets say "" is a palindrome so we recurse as 1 + f(1) => 1 + (-1) => 0
    if s[i..j] is a palindrome then we recurse in the next substring not s[j+1..n-1] and not s[i+1: ]

        instead we can update base case to be s[i..j] is a palindrome which is more intuitive
        if s[i:] is a palindrome we return 0
*/
/*
    dp[i][j] = min cuts needed to make in s[i:] to make every substring a plindrome
*/
/*
    O(n^3) approach, better alternative O(n^2) exits
        bool is_palindrome(int l, int r, string &s)
        {
            if (l >= r)
                return true;
            if (s[l] != s[r])
                return false;
            return is_palindrome(l + 1, r - 1, s);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                isPalindrome[i][j] = is_palindrome(i, j, s);
            }
        }
    */
int palindrome_cuts(int i, string &s, vector<vector<int>> &isPalindrome, vector<int> &dp)
{

    // if string is empty (s[n..n-1] = empty)
    if (isPalindrome[i][s.size() - 1])
    {
        return 0;
    }

    // if memorized
    if (dp[i] != -1)
        return dp[i];

    int min_cuts = s.size();
    for (int j = i; j < s.size(); j++)
    {
        if (isPalindrome[i][j])
            min_cuts = min(min_cuts, 1 + palindrome_cuts(j + 1, s, isPalindrome, dp));
    }
    return dp[i] = min_cuts;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> isPalindrome(n, vector<int>(n, 0));

    // O(n^2) approach to fill the isPalindrome table
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j])
            {
                if (len <= 2)
                {
                    isPalindrome[i][j] = true;
                }
                else
                {
                    isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                }
            }
        }
    }

    vector<int> dp(n, -1);
    int min_cuts = palindrome_cuts(0, s, isPalindrome, dp);

    cout << min_cuts << endl;

    return 0;
}