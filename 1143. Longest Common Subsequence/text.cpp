class Solution
{
public:
    // 前推型[更新(i,j)依賴前面，需初始化] Edit Distance、LCS、Knapsack
    // 向後傳播型[更新(i+1,j)或(i,j+1)] Interleaving String、Coin Change
    int longestCommonSubsequence(string text1, string text2)
    {
        return DP(text1, text2);
    }
    int DP(string text1, string text2)
    {
        // LCS 要多開一列 處理空字串 預設dp[0][*]代表 text1 為空字串
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));
        // 這邊用vector 預設0 用array記得初始化為0
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                // i j 先從1 開始 但對應字串要減1
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
