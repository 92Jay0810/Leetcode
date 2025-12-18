#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// 跟subset1 最大不同於 有duplicate ，因此要針對這個特性去做優化
class Solution
{
    set<vector<int>> result;

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtrack(nums, 0, subset);
        return vector<vector<int>>(result.begin(), result.end());
    }
    // subset用傳址更快
    void backtrack(vector<int> &nums, int i, vector<int> &subset)
    {
        if (nums.size() == i)
        {
            result.insert(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums, i + 1, subset);
        subset.pop_back();
        // 最主要的思路為 再不選擇nums[i]的這邊，如果nums[i]和nums[i+1]一樣 就一起跳過
        // nums={1,2,2} 某個子集為{1} 就是好例子
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
        {
            i++;
        }
        backtrack(nums, i + 1, subset);
    }
};
