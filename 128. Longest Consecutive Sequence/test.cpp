#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int longest = 0;
        for (int num : nums)
        {
            // 必須是連續陣列的開頭
            if (nums_set.find(num - 1) == nums_set.end())
            {
                int length = 1;
                while (nums_set.find(num + length) != nums_set.end())
                {
                    // 若大於一則加入長度，刪除掉該數字，增加速度
                    nums_set.erase(num + length);
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
