#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestCommonSubsequence(char *text1, char *text2)
{
    int n = strlen(text1);
    int m = strlen(text2);

    // 配置 2D 陣列 (n+1) x (m+1)，並初始化為 0

    // 2維陣列 的 指標為 int**  指向int* 的指標 malloc前面為型別 裡面為大小 需要n+1個 int*的記憶體空間
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    // 對每個 int* 做空間索取 需要m+1個位置 calloc 順便assign為0
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)calloc(m + 1, sizeof(int));
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    int result = dp[n][m];

    // 釋放記憶體
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return result;
}