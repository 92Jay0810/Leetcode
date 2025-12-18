#include <iostream>
using namespace std;
class Solution
{
public:
    /*因為回文字串分為兩種長度型態：
    1. 奇數長度回文（odd-length palindrome）

        例如："aba"、"racecar"

        中心是單一字元（像 s[1] = 'b' 為中心）

        長度為 2k+1，對稱點是某個單一字元

    2. 偶數長度回文（even-length palindrome）

        例如："abba"、"noon"

        中心是兩個字元之間（像 s[1]='b', s[2]='b' 之間）

        長度為 2k，對稱點在兩字元之間*/
    // 因為回文中心可能是1個字元或2個字元之間，所以需要分奇偶處理。
    string longestPalindrome(string s)
    {
        int resultLen = 0, resultIdx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // odd
            int left = i;
            int right = i;
            while (s[left] == s[right] && left >= 0 && right < s.size())
            {
                if (resultLen < right - left + 1)
                {
                    resultLen = right - left + 1;
                    resultIdx = left;
                }
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            // even
            while (s[left] == s[right] && left >= 0 && right < s.size())
            {
                if (resultLen < right - left + 1)
                {
                    resultLen = right - left + 1;
                    resultIdx = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(resultIdx, resultLen);
    }
};