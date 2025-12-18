class Solution
{
public:
    // 一開始不小心用了bottom up 的初始化方法
    /*Top-down (DFS + memoization)
    不需要手動初始化第一列/第一行
    只要有 base case (0,0)=1，再加上「未計算標記（-1）」即可。

    Bottom-up (DP 表格)
    需要明確初始化第一列、第一行為 1，然後依序填表：*/
    vector<vector<int>> memo;
    int uniquePaths(int m, int n)
    {
        memo.resize(m, vector<int>(n, -1));
        return dfs(m, n, m - 1, n - 1);
    }
    int dfs(int m, int n, int i, int j)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        memo[i][j] = dfs(m, n, i - 1, j) + dfs(m, n, i, j - 1);
        return memo[i][j];
    }
};