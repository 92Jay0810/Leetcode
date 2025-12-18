class Solution
{
public:
    // 跟1143 可以比較的地方 同樣是 多開 一行一列
    // 但是1143的dp[i][j]定義為 前0~i-1 0~j-1 我是向前看 去更新現在的i , j
    // 這邊的97 是向後看 我從現在的[i][j]  更新 後面的[i+1][j] [i][j+1]
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size();
        int m = s2.size();
        if ((m + n) != s3.size())
        {
            return false;
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                // 因為要完整的填表 i=n j!=m 的時候 也有最後一列要填表
                // j=m i!=n 亦是如此 只有(m,n) 不用填表
                if (!dp[i][j])
                    continue;
                if (i < n && s1[i] == s3[i + j])
                {
                    dp[i + 1][j] = true;
                }
                if (j < m && s2[j] == s3[i + j])
                {
                    dp[i][j + 1] = true;
                }
            }
        }
        return dp[n][m];
    }
};
