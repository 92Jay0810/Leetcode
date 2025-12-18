#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        unordered_map<int, int> dp;
        // 空字串為一個方法
        dp[s.size()] = 1;
        return dfs(s, 0, dp);
    }
    int dfs(string &s, int index, unordered_map<int, int> &dp)
    {
        if (dp.count(index))
        {
            return dp[index];
        }
        // 0為頭的不用管decode
        if (s[index] == '0')
        {
            return 0;
        }
        // 選擇一個位數的字母decode
        // 若為最後一位 會再將空字串的1個方法算進來
        int result = dfs(s, index + 1, dp);
        // 選擇二個位數的字母decode
        // 注意邏輯 一定要先檢查index+1<s.size() 不然把空字串的一個方法算進來會出錯
        if (index + 1 < s.size() && (s[index] == '1' || s[index] == '2' && s[index + 1] <= '6'))
        {
            result += dfs(s, index + 2, dp);
        }
        // 將一個位數、二個位數的方法總數算完 紀錄於dp後回傳
        dp[index] = result;
        return result;
    }
};
