#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        for (const auto &num : nums)
        {
            count[num]++;
        }
        // count後，key value互換 怕重複可以用pair
        vector<pair<int, int>> sortValue;
        for (const auto &num : count)
        {
            // 記得map 的元素是pair
            sortValue.push_back({num.second, num.first});
        }
        // 根據value結果去sort
        sort(sortValue.rbegin(), sortValue.rend());
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(sortValue[i].second);
        }
        return result;
    }
};