int change(int amount, int *coins, int coinsSize)
{
    // 要注意malloc的括號 size沒括號 因為優先順序而出錯
    uint **dp = (uint **)malloc((coinsSize + 1) * sizeof(uint *));
    for (int i = 0; i < coinsSize + 1; i++)
    {
        dp[i] = (uint *)calloc(amount + 1, sizeof(uint));
    }
    dp[0][0] = 1;
    for (int i = 1; i <= coinsSize; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i - 1])
            {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[coinsSize][amount];
}