#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> result(n + 1);
        result[0] = {""};
        // i<=n , 不然 i<n,n=1時，只做了result[0]
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // n=2   ( +left[0]+ ) +right[1] 、 ( +left[1]+ ) +right[0]
                for (string left : result[j])
                {
                    // 反正 j最多 i-1  , i-j-1 可以是 i- (i-1) -1 最少就0
                    for (string right : result[i - j - 1])
                    {
                        result[i].push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return result[n];
    }
};
