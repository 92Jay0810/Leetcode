class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        if (n == 0)
            return 0;
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            // Kadane's Algorithm 的影子 自己或用前面的
            dp[i] = max(nums[i] + dp[i - 1], nums[i]);
        }
        // 之後取最大
        // 不用kadane 可以做2D bottom-top dp
        // dp[i][1] 為延伸 num[i]和nums[i] + dp[i-1][0] Kadane的部分
        // dp[i][0] 為最佳 比較 dp[i-1][0] 和dp[i][1] 最大的部分
        return *max_element(dp.begin(), dp.end());
    }
};
