#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(vector<int> &arr, int n, int l, int r)
{
    if (l >= r)
        return true;
    if (arr[l] != arr[r])
        return false;
    return is_palindrome(arr, n, l + 1, r - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (is_palindrome(arr, n, 0, n - 1))
        cout << "palindromic array" << endl;
    else
        cout << "not a palindromic arr" << endl;
}