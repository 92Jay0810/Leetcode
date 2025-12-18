#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        unordered_map<int, int> map;
        int result = dfs(coins, amount, map);
        return result == INT_MAX ? -1 : result;
    }
    int dfs(vector<int> &coins, int amount, unordered_map<int, int> &map)
    {
        if (amount < 0)
        {
            return INT_MAX;
        }
        if (amount == 0)
        {
            return 0;
        }
        if (map.count(amount))
        {
            return map[amount];
        }
        int result = INT_MAX;
        // 利用resursive 達成每個硬幣選或不選
        for (int coin : coins)
        {
            // 下去算結果
            int subresult = dfs(coins, amount - coin, map);
            if (subresult != INT_MAX)
            {
                // 加1主要是因為使用了這個硬幣
                result = min(result, subresult + 1);
            }
        }

        return map[amount] = result;
    }
};
