#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_set<char> char_set(s.begin(), s.end());
        int result = 0;

        // 以每個單一char 做sliding winodws
        for (char c : char_set)
        {
            int left = 0;
            // 數一下該c 重複的次數，表示不用取代!!
            int count = 0;
            // r會不斷地向右延伸
            for (int r = 0; r < s.size(); r++)
            {
                if (s[r] == c)
                {
                    // 不用取代
                    count++;
                }
                // 一開始不會觸發，直到r延伸到一定程度，windows太大才要移動left
                // r-left+1 為windows size  -count 才是要取代的數量 >k
                while (r - left + 1 - count > k)
                {
                    if (s[left] == c)
                    {
                        count--;
                    }
                    left++;
                }
                result = max(result, r - left + 1);
            }
        }
        return result;
    }
};