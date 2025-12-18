class Solution
{
    // 這邊有一維的作法
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        // 一列留給 0元硬幣 一行留給0元預算
        vector<vector<uint>> dp(n + 1, vector<uint>(amount + 1, 0));
        // 0元硬幣 湊出0元解法
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                // coin 相關一定要i-1 因為有留一個給0元硬幣
                // 只使用i-1硬幣
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                {
                    // 再加上 第i枚硬幣
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[n][amount];
    }
};
