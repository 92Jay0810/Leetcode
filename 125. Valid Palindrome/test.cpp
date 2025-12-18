#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        // two pointer method
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            // 跳過左右空白
            while (left < right && !isAlphaNum(s[left]))
            {
                left++;
            }
            while (left < right && !isAlphaNum(s[right]))
            {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            // check完 記得替換
            left++;
            right--;
        }
        return true;
    }
    bool isAlphaNum(char c)
    {
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
    }
};
