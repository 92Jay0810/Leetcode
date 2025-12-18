#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty())
        {
            return "";
        }
        unordered_map<char, int> windows, count_t;
        for (char &c_t : t)
        {
            count_t[c_t]++;
        }
        pair<int, int> result_pair = {-1, -1};
        int result = INT_MAX;
        int left = 0;
        // judge satisfied the condition
        int have = 0;
        int need = count_t.size();
        for (int r = 0; r < s.size(); r++)
        {
            // each loop move right pointer
            windows[s[r]]++;
            if (count_t.count(s[r]) && count_t[s[r]] == windows[s[r]])
            {
                have++;
            }
            while (have == need)
            {
                // satisfy the condition , record the answer
                if (result > r - left + 1)
                {
                    result = r - left + 1;
                    result_pair = {left, r};
                }
                // continune remove left from windows
                windows[s[left]]--;
                if (count_t.count(s[left]) && count_t[s[left]] > windows[s[left]])
                {
                    have--;
                }
                left++;
            }
        }
        return result == INT_MAX ? "" : s.substr(result_pair.first, result);
    }
};
