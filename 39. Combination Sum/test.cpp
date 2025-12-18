#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> tempsum;
        backtrack(candidates, 0, target, tempsum, result);
        return result;
    }
    void backtrack(vector<int> &nums, int i, int target, vector<int> &sum, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(sum);
            return;
        }
        if (target < 0 || i >= nums.size())
        {
            return;
        }
        sum.push_back(nums[i]);
        backtrack(nums, i, target - nums[i], sum, result);
        sum.pop_back();
        backtrack(nums, i + 1, target, sum, result);
    }
};
