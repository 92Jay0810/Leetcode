#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // 自己數一下就知道了 ex 9個數字的中位數 index 5
        int left = (nums1.size() + nums2.size() + 1) / 2;
        int right = (nums1.size() + nums2.size() + 2) / 2;
        return (getKth(nums1, nums1.size(), nums2, nums2.size(), left, 0, 0) + getKth(nums1, nums1.size(), nums2, nums2.size(), right, 0, 0)) / 2.0;
    }
    int getKth(vector<int> &a, int m, vector<int> &b, int n, int k, int a_start, int b_start)
    {
        // 希望 b 是比較長的array
        if (m > n)
        {
            return getKth(b, n, a, m, k, b_start, a_start);
        }
        if (m == 0)
        {
            return b[b_start + k - 1];
        }
        // 先確認 m==0 否則會run time error
        if (k == 1)
        {
            return min(a[a_start], b[b_start]);
        }
        // a、b 都往前看 k/2個
        int i = min(m, k / 2);
        int j = min(n, k / 2);
        if (a[a_start + i - 1] > b[b_start + j - 1])
        {
            return getKth(a, m, b, n - j, k - j, a_start, b_start + j);
        }
        else
        {
            return getKth(a, m - i, b, n, k - i, a_start + i, b_start);
        }
    }
};
