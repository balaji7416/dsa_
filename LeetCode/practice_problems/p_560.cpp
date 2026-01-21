#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefix(n + 1);
        prefix[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        unordered_map<int, int> visited;
        visited[0] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int target = prefix[i + 1] - k;
            if (visited.count(target))
            {
                ans += visited[target];
            }
            visited[prefix[i + 1]] += 1;
        }
        return ans;
    }
};