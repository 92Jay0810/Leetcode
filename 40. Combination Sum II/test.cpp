#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    // 跟39. 很像，但不能重複使用candidate 只能照順序用(要排序)
    // 因此要使用i時要往下， 不用i時 要注意不要重複放一樣的
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> sum;
        dfs(candidates, 0, target, sum, result);
        return result;
    }
    void dfs(vector<int> &candidates, int i, int target, vector<int> &sum, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(sum);
            return;
        }
        if (target < 0 || i == candidates.size())
        {
            return;
        }
        sum.push_back(candidates[i]);
        dfs(candidates, i + 1, target - candidates[i], sum, result);
        sum.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
        {
            i++;
        }
        dfs(candidates, i + 1, target, sum, result);
    }
};
