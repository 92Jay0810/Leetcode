#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        int result = 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j] && (j - i + 1 <= 3 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    result++;
                }
            }
        }
        return result;
    }
};
