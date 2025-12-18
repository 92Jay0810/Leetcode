// sum/2 + 1 是為了讓 target 的最大值 sum/2 也能被存進 memo，避免越界
class Solution
{
public:
    vector<vector<int>> memo;
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        memo.resize(nums.size(), vector<int>(sum / 2 + 1, -1));
        return dfs(nums, 0, sum / 2);
    }
    bool dfs(vector<int> &nums, int i, int target)
    {
        if (i == nums.size())
        {
            return target == 0;
        }
        if (target < 0)
        {
            return false;
        }
        if (memo[i][target] != -1)
        {
            return memo[i][target];
        }
        memo[i][target] = dfs(nums, i + 1, target) || dfs(nums, i + 1, target - nums[i]);
        return memo[i][target];
    }
};
