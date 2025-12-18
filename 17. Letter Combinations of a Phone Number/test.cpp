#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<string> result;
    vector<string> digitToLetter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return result;
        }
        BackTracking(digits, 0, "");
        return result;
    }
    void BackTracking(string &digits, int index, string curr_str)
    {
        // 終止條件，因為每個digit 的char 各取一個，若size一樣則結束
        if (curr_str.size() == digits.size())
        {
            result.push_back(curr_str);
            return;
        }
        for (char c : digitToLetter[digits[index] - '0'])
        {
            // 這邊錯在原本寫++index ，會導致index被賦值
            BackTracking(digits, index + 1, curr_str + c);
        }
    }
};
