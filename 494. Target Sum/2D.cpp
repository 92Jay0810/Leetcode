class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        // 保留0個硬幣的作法 之後持續遞增硬幣的index
        vector<unordered_map<int, int>> dp(n + 1);
        // 0個硬幣 湊出0 (target) 的方法有一個
        dp[0][0] = 1;
        // i 是看nums的index (硬幣)
        for (int i = 0; i < n; i++)
        {
            for (auto &[key, value] : dp[i])
            {
                // key是sum value是幾種方法
                dp[i + 1][key + nums[i]] += value;
                dp[i + 1][key - nums[i]] += value;
            }
        }
        return dp[n][target];
    }
};
