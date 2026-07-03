#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countValidSubarrays(vector<int> &nums, int x)
    {
        int n = nums.size();

        auto ok = [&](int s)
        {
            for (int i = 0; i < 100; i++)
                cout << "-";
            cout << endl;
            cout << "received sum: " << s << endl;

            int temp = s;
            while (s > 10)
                s /= 10;

            cout << "s: " << s << " temp%10: " << temp % 10 << endl;
            for (int i = 0; i < 100; i++)
                cout << "-";
            return (s == x) && (temp % 10 == x);
        };

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                ans += ok(sum);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 100, 1};
    int x = 1;

    Solution s;
    int ans = s.countValidSubarrays(nums, x);
    cout << ans << endl;
    return 0;
}