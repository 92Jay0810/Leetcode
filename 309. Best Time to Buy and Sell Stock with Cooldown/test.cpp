class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        if (size == 0)
            return 0;
        vector<vector<int>> dp(size, vector<int>(2, 0));
        // 第0天沒股票
        dp[0][0] = 0;
        // 第0天買入
        dp[0][1] = -prices[0];
        for (int i = 1; i < size; i++)
        {
            // 今天結束手上沒股票 = 昨天沒股票 or 昨天有股票今天賣
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 今天結束手上有股票 = 昨天有股票 or 前天沒股票今天買
            if (i > 2)
            {
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            }
            else
            {
                dp[i][1] = max(dp[i - 1][1], -prices[i]);
            }
        }
        // 結束時手上沒股票才是最大收益
        return dp[size - 1][0];
    }
};
