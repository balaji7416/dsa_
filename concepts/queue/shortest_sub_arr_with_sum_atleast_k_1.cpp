#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int ans = INT_MAX;
        int n = nums.size();
        int sum = 0;
        int minm = *min_element(nums.begin(), nums.end());
        for (auto &i : nums)
        {
            i += minm;
        }
        k += minm;
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            sum += right;
            while (sum >= k)
            {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};