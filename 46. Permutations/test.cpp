#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    // 以前資結 學的方法
    // 另外有iteration、recursive 拿出num 在不同位置插入的方法
    // 還有用bit mask、vector<bool> 判斷有無選中的方法
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        backtrack(result, nums, 0);
        return result;
    }
    void backtrack(vector<vector<int>> &result, vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            backtrack(result, nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};
