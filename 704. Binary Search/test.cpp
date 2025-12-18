#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return binarysearch(0, nums.size() - 1, nums, target);
    }
    int binarysearch(int left, int right, vector<int> &nums, int target)
    {
        if (left > right)
        {
            return -1;
        }
        int m = (right + left) / 2;
        if (nums[m] == target)
        {
            return m;
        }
        else if (nums[m] < target)
        {
            return binarysearch(m + 1, right, nums, target);
        }
        else
        {
            return binarysearch(left, m - 1, nums, target);
        }
    }
};