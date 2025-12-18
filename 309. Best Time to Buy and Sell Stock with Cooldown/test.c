// max也可以做成 #define MAX(a, b) ((a) > (b) ? (a) : (b))
int max_int(int a, int b)
{
    return a > b ? a : b;
}
int maxProfit(int *prices, int pricesSize)
{
    if (pricesSize == 0)
        return 0;
    int **dp = (int **)malloc(pricesSize * sizeof(int *));
    for (int i = 0; i < pricesSize; i++)
    {
        dp[i] = (int *)calloc(2, sizeof(int));
    }
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++)
    {
        dp[i][0] = max_int(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        if (i > 2)
        {
            dp[i][1] = max_int(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }
        else
        {
            dp[i][1] = max_int(dp[i - 1][1], -prices[i]);
        }
    }
    return dp[pricesSize - 1][0];
}