#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<vector<int>> cache;

public:
    // 只要處理第一個和最後一個
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        // 用flag表示第一個
        cache.resize(nums.size(), vector<int>(2, -1));
        return max(dp(nums, true, 0), dp(nums, false, 1));
    }
    int dp(vector<int> &nums, bool flag, int house)
    {
        int n = nums.size();
        // 若有搶到第一個，則最後一個不能搶
        if (house >= n || (house == n - 1) && flag)
        {
            return 0;
        }
        if (cache[house][flag] != -1)
        {
            return cache[house][flag];
        }
        cache[house][flag] = max(dp(nums, flag, house + 1), nums[house] + dp(nums, flag, house + 2));
        return cache[house][flag];
    }
};
