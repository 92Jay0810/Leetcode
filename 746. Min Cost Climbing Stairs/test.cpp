#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<int> cache;

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        cache.resize(cost.size() + 1, -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }
    int dfs(vector<int> &cost, int i)
    {
        if (i >= cost.size())
        {
            return 0;
        }
        if (cache[i] != -1)
        {
            return cache[i];
        }
        return cache[i] = cost[i] + min(dfs(cost, i + 1), dfs(cost, i + 2));
    }
};
