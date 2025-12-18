#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int resultLen = 0;
        int resultIndex = 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // 填表順序 從右下角開始填 if n=5 , 從(4,4)、(3,3)、(3,3)、(2,2)、(2,3)、(2,4)、(1,1)、(1,2)、(1,3)、(1,4)
        // 表格的右上角都填滿 (下到上) 確保dp使用時可以使用到
        // ex (0,4) 會使用到(1,3) 因此才從n-1開始填
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                // j-i<=2 也就是長度小於3只要首尾相同一定回文
                // 長度大於三的 就檢查 前後少一個長度是否回文
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    if (resultLen < (j - i + 1))
                    {
                        resultLen = j - i + 1;
                        resultIndex = i;
                    }
                }
            }
        }
        return s.substr(resultIndex, resultLen);
    }
};