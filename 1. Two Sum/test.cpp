#include <iostream>
#include <vector>
#include <unordered_map>
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++)
        {
            int differNum = target - nums[i];

            if (hash_map.find(differNum) != hash_map.end())
            {
                return {hash_map[differNum], i};
            }
            hash_map[nums[i]] = i;
        }
        return {};
    }
};
