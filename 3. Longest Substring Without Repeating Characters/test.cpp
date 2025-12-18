#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int result = 0;
        unordered_set<char> sliding_windows;
        for (int r = 0; r < s.size(); r++)
        {
            // 碰到重複的就刪除 ex:qwerasdr => asdr 刪掉上個r和之前的字元，保留r之後的
            while (sliding_windows.find(s[r]) != sliding_windows.end())
            {
                sliding_windows.erase(s[left]);
                left++;
            }
            sliding_windows.insert(s[r]);
            result = max(result, r - left + 1);
        }
        return result;
    }
};
