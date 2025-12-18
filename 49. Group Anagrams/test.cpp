#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> divideGroup;
        for (auto &s : strs)
        {
            string sortString = s;
            sort(sortString.begin(), sortString.end());
            divideGroup[sortString].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &group : divideGroup)
        {
            result.push_back(group.second);
        }
        return result;
    }
};
