#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> mergedArr(nums1.size() + nums2.size());
        int i = 0, j = 0, k = 0;
        while (i < nums1.size() and j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
                mergedArr[k++] = nums1[i++];
            else
                mergedArr[k++] = nums2[j++];
        }
        while (i < nums1.size())
        {
            mergedArr[k++] = nums1[i++];
        }
        while (j < nums2.size())
        {
            mergedArr[k++] = nums2[j++];
        }
        int n = mergedArr.size();
        float ans;
        if (n % 2 == 1)
        {
            ans = mergedArr[n / 2];
        }
        else
        {
            ans = float(mergedArr[n / 2] + mergedArr[n / 2 - 1]) / 2;
        }
        return ans;
    }
};