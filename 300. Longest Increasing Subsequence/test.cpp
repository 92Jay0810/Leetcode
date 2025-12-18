class Solution
{
public:
    vector<int> memo;
    int dfs(vector<int> &nums, int i)
    {
        if (memo[i] != -1)
        {
            return memo[i];
        }
        int LIS = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] < nums[j])
            {
                // 這裡往下用j 不是i+1
                LIS = max(LIS, 1 + dfs(nums, j));
            }
        }
        memo[i] = LIS;
        return LIS;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        memo.assign(n, -1);
        int LIS = 1;
        for (int i = 0; i < n; i++)
        {
            LIS = max(LIS, dfs(nums, i));
        }
        return LIS;
    }
};
