#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> cache;
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        cache.resize(n, -1);
        return dp(nums, 0);
    }
    int dp(vector<int> &nums, int house)
    {
        if (house >= nums.size())
        {
            return 0;
        }
        if (cache[house] != -1)
        {
            return cache[house];
        }
        cache[house] = max(dp(nums, house + 1), nums[house] + dp(nums, house + 2));
        return cache[house];
    }
};
