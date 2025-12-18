#include <iostream>
#include <vector>
class Solution
{
    std::vector<int> cache;
    // 1D DP top to bottom
    // 簡單來說，每一輪都會去 +1 或+2 只要最後數字一樣就會return 1 視為一種成功方法
public:
    int climbStairs(int n)
    {
        cache.resize(n + 1, -1);
        return dfs(n, 0);
    }
    int dfs(int n, int curr_stair)
    {
        if (curr_stair >= n)
        {
            return curr_stair == n;
        }
        if (cache[curr_stair] != -1)
        {
            return cache[curr_stair];
        }
        return cache[curr_stair] = dfs(n, curr_stair + 1) + dfs(n, curr_stair + 2);
    }
};